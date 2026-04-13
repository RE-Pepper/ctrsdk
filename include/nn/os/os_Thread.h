#pragma once

RP_SHUTUP

#include <nn/Result.h>
#include <nn/fnd/fnd_TimeSpan.h>
#include <nn/os/os_SvcTypes.autogen.h>
#include <nn/os/os_Synchronization.h>
#include <nn/util/util_TypeTraits.h>

#include "nn/os/CTR/os_ErrorHandler.h"
#include "nn/svc/svc_Stub.h"

namespace nn {
namespace os {

namespace detail {
s32  ConvertSvcToLibraryPriority(s32 svc);
s32  ConvertLibraryToSvcPriority(s32 lib);
void InitializeThreadEnvironment();
} // namespace detail

template <size_t Size>
class StackBuffer
{
private:
        util::aligned_storage<Size, 8> m_Buffer; // 8 is derived from u64

public:
        uptr GetStackBottom();

        StackBuffer() {}
};

class Thread : WaitObject
{
private:
        typedef struct AutoStackManager AutoStackManager; // 154

        struct InitializeAsCurrentTag
        {};

        struct TypeInfo {
                size_t size;

                void (*copy)(const void* src, void* dsr);
                void (*destroy)(void* p);
                void (*invoke)(ThreadFunc f, const void* p);

                template <typename T1, typename T2, typename T3>
                void SetData() // TODO: PARAMETERS
                {
                        size = sizeof(T1);
                        // TODO
                }

                template <typename T1, typename T2>
                void Copy(const void* src, void* dst) { new (dst) T1(*(const T2*)src); }

                template <typename T>
                void Destroy(void* p) {}

                template <typename T>
                void Invoke(ThreadFunc f, const void* p) { f((uptr)p); }
        };

        struct FunctionInfo;

public:
        Thread() : m_CanFinalize(true) {} // 166
        ~Thread();

        void Finalize();
        void Join();

        bool  IsAlive() const;
        void  Sleep(fnd::TimeSpan span);
        void  Yield();
        bit32 GetId() const;
        bit32 GetCurrentId() const;
        s32   GetPriority() const;
        s32   GetCurrentPriority() const;
        void  ChangePriority(s32 priority);
        void  ChangeCurrentPriority(s32 priority);
        s32   GetIdealProcessor() const;
        s32   GetDefaultIdealProcessor() const;
        s32   GetCurrentProcessorNumber() const;

private:
        bool m_CanFinalize;
        bool m_UsingAutoStack;
        int  unk; // unnamed int

        static Thread            s_MainThread;
        static AutoStackManager* s_pAutoStackManager;

public:
        static Thread& GetMainThread() { return s_MainThread; }

        void SetAutoStackManager(AutoStackManager* pManager) { s_pAutoStackManager = pManager; }

        Thread(const InitializeAsCurrentTag&);

        void FinalizeImpl();

        Result TryInitializeAndStartImpl (TypeInfo typeInfo, ThreadFunc f, const void* p, uptr stackBottom, s32 priority, s32 coreNo, bool isAutoStack);
        Result TryInitializeAndStartImplUsingAutoStack(TypeInfo typeInfo, ThreadFunc f, const void* p, size_t stackSize, s32 priority, s32 coreNo);

        static void OnThreadStart();
        static void OnThreadExit();
        static void ThreadStart(uptr p);
        void        NoParameterFunc(void (*f)());

        void SleepImpl(fnd::TimeSpan span);

        void* CallDestructorAndExit();

        template <typename T1, typename T2, typename Thread>
        void StartUsingAutoStack(T1 f, T2 param, size_t stackSize, s32 priority, s32 coreNo);

        template <typename T1, typename T2, typename Stack>
        Result TryStart(void (*f)(T1), T2 param, Stack* stack, s32 priority, s32 coreNo);

        template <typename T1, typename T2, typename Stack>
        void Start(void (*f)(T1), T2 param, Stack& stack, s32 priority, s32 coreNo = 254);
};

inline void Thread::Finalize()
{
        FinalizeImpl(); // 878
        HandleObject::Finalize();
}

inline Thread::~Thread()
{
        FinalizeImpl(); // 884 / 963
}

inline bool Thread::IsAlive() const
{
        if (!IsValid()) { // / 981
                return false;
        }

        return !((Thread*)this)->WaitOne(0);
}

inline void Thread::Sleep(fnd::TimeSpan span)
{
        SleepImpl(span);
}

inline void Thread::Yield()
{
        svc::SleepThread(0);
}

inline bit32 Thread::GetId() const
{
        bit32 ret;
        NN_OS_HANDLE_ERROR(nn::svc::GetThreadId(&ret, GetHandle()));
        return ret;
}

inline bit32 Thread::GetCurrentId() const
{
        bit32 ret;
        NN_OS_HANDLE_ERROR(nn::svc::GetThreadId(&ret, PSEUDO_HANDLE_CURRENT_THREAD));
        return ret;
}

inline s32 Thread::GetPriority() const
{
        s32 ret;
        NN_OS_HANDLE_ERROR(nn::svc::GetThreadPriority(&ret, GetHandle()));
        return ret;
}

inline s32 Thread::GetCurrentPriority() const
{
        s32 ret;
        NN_OS_HANDLE_ERROR(nn::svc::GetThreadPriority(&ret, PSEUDO_HANDLE_CURRENT_THREAD));
        return ret;
}

inline void Thread::ChangePriority(s32 priority)
{
        NN_OS_HANDLE_ERROR(svc::SetThreadPriority(GetHandle(), detail::ConvertLibraryToSvcPriority(priority)));
}

inline void Thread::ChangeCurrentPriority(s32 priority)
{
        NN_OS_HANDLE_ERROR(svc::SetThreadPriority(PSEUDO_HANDLE_CURRENT_THREAD, detail::ConvertLibraryToSvcPriority(priority)));
}

inline s32 Thread::GetIdealProcessor() const
{
        //TODO
}

inline s32 Thread::GetDefaultIdealProcessor() const
{
        //TODO
}

inline s32 Thread::GetCurrentProcessorNumber() const
{
        //TODO
}

} // namespace os
} // namespace nn

#ifdef __cplusplus
extern "C" {
#endif

typedef union nnosThread {
} nnosThread;

// nnos..(); come here

#ifdef __cplusplus
}
#endif
