#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {
namespace srv {
namespace detail {

class Service
{
private:
        static Handle s_Session;

public:
        Service() {}

        static Result RegisterClient();
        static Result EnableNotification(Handle* pSemaphore);
        static Result RegisterService(Handle*, const char8*, s32, s32);
        static Result UnregisterService(const char8*, s32);
        static Result GetServiceHandle(Handle* pOut, const char8* name, s32 nameLen, bit32 flags);
        static Result RegisterObject(Handle handle, const char8* name, s32 nameLen);
        static Result UnregisterObject(const char8* name, s32);
        static Result GetNamedObject(Handle* pOut, const char8* name, s32 nameLen, bool wait);
        static Result Subscribe(bit32);
        static Result Unsubscribe(bit32);
        static Result ReceiveNotification(bit32* pOut);
        static Result PublishToSubscriber(bit32, bit32, bit32);
        static Result IsServiceRegistered(bool*, const char8*, s32);
};

} // namespace detail
} // namespace srv
} // namespace nn
