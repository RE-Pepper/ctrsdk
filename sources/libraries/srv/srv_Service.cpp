#include <nn/os/ipc/os_SessionMessage.h>
#include <nn/srv/srv_Service.h>
#include <nn/svc/svc_Stub.h>

RP_SHUTUP

namespace nn {
namespace srv {
namespace detail {

varc(nn::srv::detail, Service, s_Session, Handle) = 0;

Result Service::RegisterClient()
{ // 47
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(1, 0, 2, 0);
        ipcMsg.SetProcessIdHeader(1);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::EnableNotification(Handle* pSemaphore)
{ // 62
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(2, 0, 0, 0);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        *pSemaphore = ipcMsg.GetHandle(3);

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::RegisterService(Handle*, const char8*, s32, s32)
{
        // TODO
}

Result Service::UnregisterService(const char8*, s32)
{
        // TODO
}

Result Service::GetServiceHandle(Handle* pOut, const char8* name, s32 nameLen, bit32 flags)
{ // 130
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(5, 4, 0, 0);
        ipcMsg.SetRawArray(1, name, sizeof(*name) * 8);
        ipcMsg.SetRaw(3, nameLen);
        ipcMsg.SetRaw(4, flags);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        *pOut = ipcMsg.GetHandle(3);

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::RegisterObject(Handle handle, const char8* name, s32 nameLen)
{ // 153
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(6, 3, 2, 0);
        ipcMsg.SetRawArray(1, name, sizeof(*name) * 8);
        ipcMsg.SetRaw(3, nameLen);
        ipcMsg.SetCopyHandleHeader(4, 1);
        ipcMsg.SetHandle(5, handle);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::UnregisterObject(const char8*, s32)
{
        // TODO
}

Result Service::GetNamedObject(Handle* pOut, const char8* name, s32 nameLen, bool wait)
{ // 198
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(8, 4, 0, 0);
        ipcMsg.SetRawArray(1, name, sizeof(*name) * 8);
        ipcMsg.SetRaw(3, nameLen);
        ipcMsg.SetRaw(4, wait);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::Subscribe(bit32 message)
{
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(9, 1, 0, 0);
        ipcMsg.SetRaw(1, message);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::Unsubscribe(bit32 message)
{
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(10, 1, 0, 0);
        ipcMsg.SetRaw(1, message);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::ReceiveNotification(bit32* pOut)
{
        os::ipc::MessageBuffer ipcMsg = os::ipc::MessageBuffer(os::ipc::GetMessageBuffer());
        ipcMsg.SetHeader(11, 0, 0, 0);

        Result ipcResult = svc::SendSyncRequest(s_Session);
        if (ipcResult.IsFailure()) {
                return ipcResult;
        }

        *pOut = ipcMsg.GetRaw<bit32>(2);

        return ipcMsg.GetRaw<Result>(1);
}

Result Service::PublishToSubscriber(bit32, bit32, bit32)
{
        // TODO
}

Result Service::IsServiceRegistered(bool* pOut, const char8*, s32)
{
        // TODO
}

} // namespace detail
} // namespace srv
} // namespace nn
