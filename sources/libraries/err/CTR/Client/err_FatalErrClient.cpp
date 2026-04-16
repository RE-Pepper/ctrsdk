#include <nn/err/CTR/err_FatalErrIpc.h>
#include <nn/os/ipc/os_SessionMessage.h>
#include <nn/svc/svc_Stub.h>

#include "nn/err/CTR/err_FatalErrInfo.h"

namespace nn {
namespace err {
namespace CTR {

Result FatalErr::Throw(const FatalErrInfo& info)
{ // 41
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(1, 32, 0, 0);
        ipcMsg.SetRaw<FatalErrInfo>(1, info);

        Result ipcResult = svc::SendSyncRequest(m_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result FatalErr::SetUserString(const s8*, size_t)
{
        RP_SHUTUP
        // TODO
}

} // namespace CTR
} // namespace err
} // namespace nn
