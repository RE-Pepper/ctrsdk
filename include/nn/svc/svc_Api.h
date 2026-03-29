#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/dbg/dbg_Enum.h>
#include <nn/os/os_Types.h>

namespace nn {
namespace svc {

nn::Result ControlMemory(u32* addr, u32 addr0, u32 addr1, u32 size, u32 op, u32 perms);
void       ExitProcess();
void       SleepThread(u64 nanos);
nn::Result GetThreadPriority(s32* prio, nn::Handle thread);
nn::Result CreateMutex(nn::Handle* mutex, bool initialLocked);
nn::Result CreateEvent(nn::Handle* event, nn::os::ResetType type);
nn::Result CreateMemoryBlock(nn::Handle* memblock, u32 addr, u32 size, u32 myperms, u32 otherperms);
nn::Result CreateAddressArbiter(nn::Handle* arbiter);
nn::Result ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns);
nn::Result CloseHandle(nn::Handle handle);
nn::Result WaitSynchronizationN(int* out, const nn::Handle* handles, s32 handleCount, bool waitAll, s64 timeout_ns);
nn::Result DuplicateHandle(nn::Handle* out, nn::Handle original);
nn::Result ConnectToPort(nn::Handle* port, const char* portName);
nn::Result GetProcessId(unsigned int* id, nn::Handle handle);
nn::Result GetThreadId(unsigned int* id, nn::Handle handle);
nn::Result GetResourceLimit(Handle* resourceLimit, nn::Handle handle);

// Debug
nn::Result Break(nn::dbg::BreakReason reason);

} // namespace svc
} // namespace nn
