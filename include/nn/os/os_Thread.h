#pragma once

#include <nn/Result.h>
#include <nn/fnd/fnd_TimeSpan.h>
#include <nn/os/os_SvcTypes.autogen.h>
#include <nn/os/os_Synchronization.h>
#include <nn/util/util_TypeTraits.h>

namespace nn {
namespace os {

template <size_t Size>
class StackBuffer
{
private:
        util::aligned_storage<Size, 8> m_Buffer; // 8 is derived from u64

public:
        uptr GetStackBottom ();

        StackBuffer () {}
};

class Thread : WaitObject
{
private:
        typedef struct AutoStackManager AutoStackManager; // 154

        struct InitializeAsCurrentTag
        {};

        struct TypeInfo {
                size_t size;

                void (*copy) (const void*, void*);
                void (*destroy) (void*);
                void (*invoke) (ThreadFunc, const void*);

                template <typename T1, typename T2, typename T3>
                void SetData (); // parameters todo

                template <typename T1, typename T2>
                void Copy (const void*, void*);

                template <typename T>
                void Destroy (void*);

                template <typename T>
                void Invoke (ThreadFunc, const void*);
        };

        struct FunctionInfo;

private:
        bool m_CanFinalize;
        bool m_UsingAutoStack;
        int  unk; // unnamed int

        static Thread            s_MainThread;
        static AutoStackManager* s_pAutoStackManager;

public:
        Thread () {}
        ~Thread () {}

        void Finalize ();
        void Join ();

        bool  IsAlive ();
        void  Sleep (fnd::TimeSpan);
        void  Yield ();
        bit32 GetId ();
        bit32 GetCurrentId ();
        s32   GetPriority ();
        s32   GetCurrentPriority ();
        void  ChangePriority (s32);
        void  ChangeCurrentPriority (s32);
        s32   GetIdealProcessor ();
        s32   GetDefaultIdealProcessor ();
        s32   GetCurrentProcessorNumber ();

        static Thread& GetMainThread ();

        void SetAutoStackManager (AutoStackManager*);
        s32  GetCurrentCount ();
        s32  GetMaxCount ();

        Thread (const InitializeAsCurrentTag&) {}

        void FinalizeImpl ();

        Result TryInitializeAndStartImpl (TypeInfo, ThreadFunc, const void*, uptr, s32, s32, bool);
        Result TryInitializeAndStartImplUsingAutoStack(TypeInfo, ThreadFunc, const void*, size_t, s32, s32);

        static void OnThreadStart ();
        static void OnThreadExit ();
        static void ThreadStart (uptr);
        void        NoParameterFunc (void (*) ());

        void SleepImpl (fnd::TimeSpan);

        void* CallDestructorAndExit ();

        template <typename T1, typename T2, typename Thread>
        void StartUsingAutoStack (T1, T2, size_t, s32, s32);

        template <typename T1, typename T2, typename Stack>
        Result TryStart (void (*func) (), T2, Stack, s32, s32);

        template <typename T1, typename T2, typename Stack>
        void Start (void (*func) (), T2, Stack&, s32, s32 = 254);
};

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
