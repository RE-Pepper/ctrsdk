#include <nn/os/os_SvcTypes.autogen.h>
#include <nn/svc/svc_Stub.h>

namespace nn {
namespace svc {

Result
asm_ext(ControlMemory, ".nn.svc.ControlMemory")(uptr* pOut, uptr addr0, uptr addr1, size_t size, u32 op, u32 perms) // 37
{
        push { r0, r4 };
        ldr r0, [ sp, #8 ];
        ldr r4, [ sp, #0xc ];
        svc 0x1;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        pop { r4 };
        bx lr;
}

Result asm_ext(QueryMemory, ".nn.svc.QueryMemory")(nn::os::MemoryInfo* mem, nn::os::PageInfo* page, u32 num) // 50
{
        push { r0, r1, r4 - r6 };
        svc 2;
        ldr r6, [ sp, #0x4 ];
        str r1, [r6];
        str r2, [ r6, #0x4 ];
        str r3, [ r6, #0x8 ];
        str r4, [ r6, #0xC ];
        ldr r6, [ sp, #4 ];
        str r5, [r6];
        add sp, sp, #8;
        pop { R4 - R6 };
        bx lr;
}

void asm_ext(ExitProcess, ".nn.svc.ExitProcess")()
{
        svc 0x3;
        bx lr;
}

void asm_ext(CreateThread, ".nn.svc.CreateThread")(Handle* handle, void (*func)(u32), u32 arg, u32 stackTop, s32 prio, s32 processorId)
{
        push { r0, r4 };
        ldr r0, [ sp, #8 ];
        ldr r4, [ sp, #0xc ];
        svc 0x8;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        pop { r4 };
        bx lr;
}

void asm_ext(SleepThread, ".nn.svc.SleepThread")(u64 nanos)
{
        svc 0xa;
        bx lr;
}

Result asm_ext(GetThreadPriority, ".nn.svc.GetThreadPriority")(s32* prio, Handle thread)
{
        push { r0 };
        svc 0xb;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(SetThreadPriority, ".nn.svc.SetThreadPriority")(Handle thread, int prio)
{
        svc 0xC;
        bx lr;
}

u32 asm_ext(GetCurrentProcessorNumber, ".nn.svc.GetCurrentProcessorNumber")()
{
        svc 0x11;
        bx lr;
}

Result asm_ext(CreateMutex, ".nn.svc.CreateMutex")(Handle* mutex, bool initialLocked)
{
        push { r0 };
        svc 0x13;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(ReleaseMutex, ".nn.svc.ReleaseMutex")(Handle mutex)
{
        svc 0x14;
        bx lr;
}

Result asm_ext(CreateEvent, ".nn.svc.CreateEvent")(Handle* event, nn::os::ResetType type)
{
        push { r0 };
        svc 0x17;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(SignalEvent, ".nn.svc.SignalEvent")(Handle event)
{
        svc 0x18;
        bx lr;
}

Result asm_ext(ClearEvent, ".nn.svc.ClearEvent")(Handle mutex)
{
        svc 0x19;
        bx lr;
}

Result asm_ext(CreateMemoryBlock, ".nn.svc.CreateMemoryBlock")(Handle* memblock, u32 addr, u32 size, u32 myperms, u32 otherperms)
{
        push { r0 };
        ldr r0, [ sp, #4 ];
        svc 0x1e;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(MapMemoryBlock, ".nn.svc.MapMemoryBlock")(Handle block, u32 i0, u32 start, u32 end)
{
        svc 0x1F;
        bx lr;
}

Result asm_ext(UnmapMemoryBlock, ".nn.svc.UnmapMemoryBlock")(Handle block, u32 i0)
{
        svc 0x20;
        bx lr;
}

Result asm_ext(CreateAddressArbiter, ".nn.svc.CreateAddressArbiter")(Handle* arbiter)
{
        push { r0 };
        svc 0x21;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(ArbitrateAddress, ".nn.svc.ArbitrateAddress")(Handle arbiter, uptr addr, nn::os::ArbitrationType type, s32 value, s64 ns)
{
        svc 0x22;
        bx lr;
}

Result asm_ext(CloseHandle, ".nn.svc.CloseHandle")(Handle handle)
{
        svc 0x23;
        bx lr;
}

Result asm_ext(WaitSynchronizationN, ".nn.svc.WaitSynchronizationN")(int* pOut, const Handle* handles, s32 handleCount, bool waitAll, s64 timeout_ns)
{
        push { r0, r4 };
        ldr r0, [ sp, #8 ];
        ldr r4, [ sp, #0xC ];
        svc 0x25;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        pop { r4 };
        bx lr;
}

Result asm_ext(WaitSynchronization1, ".nn.svc.WaitSynchronization1")(int* pOut, s64 timeout_ns)
{
        SVC 0x24;
        BX lr;
}

Result asm_ext(DuplicateHandle, ".nn.svc.DuplicateHandle")(Handle* pOut, Handle original)
{
        push { r0 };
        svc 0x27;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

u32 asm_ext(GetSystemTick, ".nn.svc.GetSystemTick")()
{
        svc 0x28;
        bx lr;
}

Result asm_ext(GetProcessInfo, ".nn.svc.GetProcessInfo")(u64* num, Handle handle, nn::os::ProcessInfoType infoType)
{
        push { r0 };
        svc 0x2B;
        ldr r3, [sp];
        str r1, [r3];
        str r2, [ r3, #0x4 ];
        add sp, sp, #0x4;
        bx  lr;
}

Result asm_ext(ConnectToPort, ".nn.svc.ConnectToPort")(Handle* port, const char* portName)
{
        push { r0 };
        svc 0x2D;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(SendSyncRequest, ".nn.svc.SendSyncRequest")(Handle handle)
{
        svc 0x32;
        bx lr;
}

Result asm_ext(GetProcessId, ".nn.svc.GetProcessId")(u32* id, Handle handle)
{
        push { r0 };
        svc 0x35;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(GetThreadId, ".nn.svc.GetThreadId")(u32* id, Handle handle)
{
        push { r0 };
        svc 0x37;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

Result asm_ext(GetResourceLimit, ".nn.svc.GetResourceLimit")(Handle* resourceLimit, Handle handle)
{
        push { r0 };
        svc 0x38;
        ldr r2, [sp];
        str r1, [r2];
        add sp, sp, #4;
        bx  lr;
}

} // namespace svc
} // namespace nn
