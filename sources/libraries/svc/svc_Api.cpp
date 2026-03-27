#include <nn/svc/svc_Api.h>

namespace nn {
namespace svc {

    // clang-format off

    nn::Result asm(ControlMemory)(u32* addr, u32 addr0, u32 addr1, u32 size, u32 op, u32 perms)
    {
        push {r0, r4}
        ldr r0, [sp, #8]
        ldr r4, [sp, #0xc]
        svc 0x1
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    void asm(ExitProcess)()
    {
        svc 0x3
        bx lr
    }

    void asm(CreateThread)(nn::Handle* handle, void (*func)(u32), u32 arg, u32 stackTop, s32 prio, s32 processorId)
    {
        push {r0, r4}
        ldr r0, [sp, #8]
        ldr r4, [sp, #0xc]
        svc 0x8
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    void asm(SleepThread)(u64 nanos)
    {
        svc 0xa
        bx lr
    }

    nn::Result asm(GetThreadPriority)(s32* prio, nn::Handle thread)
    {
        push {r0}
        svc 0xb
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(CreateMutex)(nn::Handle* mutex, bool initialLocked)
    {
        push {r0}
        svc 0x13
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(CreateEvent)(nn::Handle* event, nn::os::ResetType type)
    {
        push {r0}
        svc 0x17
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(CreateMemoryBlock)(nn::Handle* memblock, u32 addr, u32 size, u32 myperms, u32 otherperms)
    {
        push {r0}
        ldr r0, [sp, #4]
        svc 0x1e
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(CreateAddressArbiter)(nn::Handle* arbiter)
    {
        push {r0}
        svc 0x21
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(ArbitrateAddress)(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns)
    {
        svc 0x22
        bx lr
    }

    nn::Result asm(CloseHandle)(nn::Handle handle)
    {
        svc 0x23
        bx lr
    }

    nn::Result asm(WaitSynchronizationN)(int* out, const nn::Handle* handles, s32 handleCount, bool waitAll, s64 timeout_ns)
    {
        push {r0, r4}
        ldr r0, [sp, #8]
        ldr r4, [sp, #0xC]
        svc 0x25
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    nn::Result asm(DuplicateHandle)(nn::Handle* out, nn::Handle original)
    {
        push {r0}
        svc 0x27
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(ConnectToPort)(nn::Handle* port, const char* portName)
    {
        push {r0}
        svc 0x2D
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(GetProcessId)(unsigned int *id, nn::Handle handle)
    {
        push {r0}
        svc 0x35
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(GetThreadId)(unsigned int *id, nn::Handle handle)
    {
        push {r0}
        svc 0x37
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    nn::Result asm(GetResourceLimit)(Handle *resourceLimit, nn::Handle handle)
    {
        push {r0}
        svc 0x38
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    // Debug
    nn::Result asm(Break)(nn::dbg::BreakReason reason)
    {
        svc 0x3c
        bx lr
    }

    // clang-format on

} // namespace svc
} // namespace nn
