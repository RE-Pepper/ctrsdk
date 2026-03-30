#pragma once

#include <nn/Result.h>
#include <nn/WithInitialize.h>
#include <nn/os/os_WaitableCounter.h>
#include <nn/util/util_NonCopyable.h>

#include "nn/assert.h"

namespace nn {
namespace os {

struct CriticalSection : nn::util::ADLFireWall::NonCopyable<CriticalSection>
{
private:
        struct ReverseIfPositiveUpdater
        {
                bool operator() (s32& x)
                {
                        if (x > 0) {
                                x = -x;
                                return true;
                        }
                        return false;
                }
        };
        struct ReverseUpdater
        {
                s32 afterUpdate;

                bool operator() (s32& x)
                {
                        x           = -x;
                        afterUpdate = x;
                        return true;
                }
        };

        struct ScopedLock
        {
        private:
                CriticalSection& m_Reference;

        public:
                ScopedLock (CriticalSection& section)
                    : m_Reference (section)
                {
                        m_Reference.Enter ();
                }
                ~ScopedLock ()
                {
                        m_Reference.Leave ();
                }
        };

        WaitableCounter m_Counter;
        uptr            m_ThreadUniqueValue;
        s32             m_LockCount;

public:
        void Initialize ()
        {
                *m_Counter          = 1;
                m_ThreadUniqueValue = GetInvalidThreadUniqueValue ();
                m_LockCount         = 0;
        }
        bool IsInitialized () const { return m_LockCount >= 0; }
        void Finalize () { m_LockCount = -1; }
        void Enter ()
        {
                NN_ASSERT_SDK (IsInitialized ());
                if (!LockedByCurrentThread () && !TryEnterImpl ()) {
                        EnterImpl ();
                }
                ++m_LockCount;
        }
        void Leave ()
        {
                NN_ASSERT_SDK (IsInitialized ());
                NN_ASSERT_SDK_EX (LockedByCurrentThread () && m_LockCount > 0,
                        "CriticalSection is not entered on the current thread.");

                if (--m_LockCount == 0) {
                        NN_ASSERT_SDK_EX (*m_Counter < 0, "CriticalSection is not entered.");
                        m_ThreadUniqueValue = GetInvalidThreadUniqueValue ();
                        ReverseUpdater updater;
                        m_Counter->AtomicUpdateConditional (updater);

                        if (updater.afterUpdate > 1) {
                                m_Counter.Signal (1);
                        }
                }
        }

        Result TryInitialize ()
        {
                Initialize ();
                return ResultSuccess ();
        }
        bool TryEnter ()
        {
                NN_ASSERT_SDK (IsInitialized ());
                if (LockedByCurrentThread () || TryEnterImpl ()) {
                        ++m_LockCount;
                        return true;
                }
                return false;
        }

        void EnterImpl ();
        bool TryEnterImpl ()
        {
                ReverseIfPositiveUpdater updater;
                if (m_Counter->AtomicUpdateConditional (updater)) {
                        NN_ASSERT_SDK (m_LockCount == 0);
                        m_ThreadUniqueValue = GetThreadUniqueValue ();
                        return true;
                }
                return false;
        }

        uptr GetThreadUniqueValue ()
        {
                //uptr v;
                // TODO
                return 0;
        }
        uptr GetInvalidThreadUniqueValue ()
        {
                return 0;
                
        }
        bool LockedByCurrentThread ()
        {
                return GetThreadUniqueValue () == m_ThreadUniqueValue;
        }

public:
        CriticalSection ()
            : m_ThreadUniqueValue (GetInvalidThreadUniqueValue ()),
              m_LockCount (-1)
        {}
        CriticalSection (const WithInitialize&)
        {
                Initialize ();
        }
        ~CriticalSection () {}
};

} // namespace os
} // namespace nn

