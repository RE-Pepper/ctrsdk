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

s32 ConvertLibraryToSvcPriority(s32 lib)
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

void InitializeThreadEnvironment()
{
        ThreadLocalStorage::ClearAllSlots();
        //CTR::SetupThreadCppExceptionEnvironment();
        _fp_init();
}

} // namespace detail

void Thread::FinalizeImpl()
{
        // TODO
}

} // namespace os
} // namespace nn
