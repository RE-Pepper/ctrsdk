#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fnd/fnd_LinkedList.h>
#include <nn/os/os_LightEvent.h>

namespace nn {
namespace srv {

template <class T>
class EventNotificationHandlerBase
{
private:
        os::LightEvent* m_pEvent;

public:
        EventNotificationHandlerBase () {}

        void Initialize (os::LightEvent* event) {}

        virtual void v0 ();
        virtual void v1 ();
        virtual void v2 ();
        virtual void v3 ();
        virtual void v4 ();
        virtual void v5 ();
        virtual void HandleNotification (bit32) {}
};

class NotificationHandler : public nn::fnd::IntrusiveLinkedList<NotificationHandler>::Item
{
private:
        bit32 m_AttachedMessage;

public:
        NotificationHandler () {}
};

typedef EventNotificationHandlerBase<NotificationHandler*> LightEventNotificationHandler; // 122

Result Initialize ();
Result GetServiceHandle (Handle* out, const char* service, s32, u32);

} // namespace srv
} // namespace nn
