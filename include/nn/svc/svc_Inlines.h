#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/svc/svc_Stub.h>

namespace nn {
namespace svc {

inline Result WaitSynchronization(s32* pOut, Handle* handles, s32 numHandles, bool waitAll, s64 timeout)
{
        return WaitSynchronizationN(pOut, handles, numHandles, waitAll, timeout);
}

} // namespace svc
} // namespace nn

