#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {
namespace srv {
namespace detail {

class Manager
{
private:
        Handle s_Session;

public:
        static Result RegisterClient ();
        static Result EnableNotification ();
        static Result RegisterService (Handle*, const char8*, s32, s32);
        static Result UnregisterService (const char8*, s32);
        static Result GetServiceHandle (Handle*, const char8*, s32, bit32);
        static Result RegisterObject (Handle, const char8*, s32);
        static Result UnregisterObject (const char8*, s32);
        static Result GetNamedObject (Handle*, const char8*, s32, bool);
        static Result Subscribe (bit32);
        static Result Unsubscribe (bit32);
        static Result ReceiveNotifictions (bit32);
        static Result PublishToSubscriber (bit32, bit32);
        static Result PublishAndGetSubscriber (s32, bit32, bit32);
        static Result IsServiceRegistered (bool*, const char8*, s32);
        static Result PublishToProcess (Handle, bit32);
        static Result PublishToAll (bit32);
        static Result RegisterProcess (bit32, const bit32*, s32);
        static Result UnregisterProcess (bit32);
};

} // namespace detail
} // namespace srv
} // namespace nn
