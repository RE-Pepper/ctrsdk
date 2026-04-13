#include <nn/os/CTR/os_CppException.h>
#include <nn/os/os_Thread.h>
#include <nn/os/os_ThreadLocalStorage.h>
#include <rt_fp.h>

namespace nn {
namespace os {

namespace detail {

s32 ConvertSvcToLibraryPriority(s32 svc) // 46
{
        if (svc >= 32) {
                const s32 offset = svc - 32;
                return offset;
        } else if (svc >= 24) {
                const s32 offset = svc - 24;
                return offset + 0x5109D500;
        } else {
                return svc + 0x6C8DA500;
        }
}

s32 ConvertLibraryToSvcPriority(s32 lib) // 68
{
        if (lib >= 0 && lib <= 32) {
                return 32 + lib;
        }
        if (lib >= 0x5109D500 && lib <= 0x5109D527) {
                const s32 offset = lib - 0x5109D500;
                return 24 + offset;
        }
        if (lib >= 0x6C8DA500 && lib <= 0x6C8DA540) {
                const s32 offset = lib - 0x6C8DA500;
                return 0 + offset;
        }

        return -1;
}

void InitializeThreadEnvrionment() // 91
{
        ThreadLocalStorage::ClearAllSlots();
        CTR::SetupThreadCppExceptionEnvironment();
        _fp_init();
}

} // namespace detail

void Thread::OnThreadStart() // 142
{
        // TODO
}

void Thread::OnThreadExit() // 148
{
        // TODO
}

void Thread::NoParameterFunc(void (*f)()) // 151
{
        // TODO
}

void* Thread::CallDestructorAndExit() // 164
{
        // TODO
}

void Thread::ThreadStart(uptr p) // 181
{
        // TODO
}

Result Thread::TryInitializeAndStartImpl (TypeInfo typeInfo, ThreadFunc f, const void* p, uptr stackBottom, s32 priority, s32 coreNo, bool isAutoStack) // 200
{
        // TODO
}

Result Thread::TryInitializeAndStartImplUsingAutoStack(TypeInfo typeInfo, ThreadFunc f, const void* p, size_t stackSize, s32 priority, s32 coreNo) // 256
{
        // TODO
}

void Thread::SleepImpl(fnd::TimeSpan span) // 242
{
        // TODO
}

Thread::Thread(const InitializeAsCurrentTag&) // 281
{
        // TODO
}

void Thread::FinalizeImpl() // 295
{
        // TODO
}

} // namespace os
} // namespace nn

extern "C" {

//nnosThreadYield(); nnosThreadSleep(s64 nanoSeconds);
}
