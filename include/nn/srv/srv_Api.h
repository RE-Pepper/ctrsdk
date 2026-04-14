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
        EventNotificationHandlerBase() {}

        void Initialize(os::LightEvent* event) {}

        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void HandleNotification(bit32) {}
};

struct NotificationHandler : public nn::fnd::IntrusiveLinkedList<NotificationHandler>::Item
{
        bit32 m_AttachedMessage;

        NotificationHandler() {}
};

typedef EventNotificationHandlerBase<NotificationHandler*> LightEventNotificationHandler; // 122

Result Initialize();
Result GetServiceHandle(Handle* pOut, const char8* pName, s32 length, bit32 flags);

inline Result ReceiveNotification(bit32 pOut) // 265
{
        // TODO
}
inline Result GetServiceHandle(Handle* pOut, const char8* pName) // 308
{
        s32 length;
        // TODO
}
inline Result TryGetServiceHandle(Handle* pOut, const char8* pName) // 319
{
        s32 length;
        // TODO
}

} // namespace srv
} // namespace nn
