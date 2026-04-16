#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/assert.h>
#include <nn/fnd/fnd_LinkedList.h>
#include <nn/os/os_LightEvent.h>
#include <nn/srv/srv_Service.h>
#include <string.h>

namespace nn {
namespace srv {

class NotificationHandler : public nn::fnd::IntrusiveLinkedList<NotificationHandler>::Item
{
public:
        bit32 m_AttachedMessage;

        NotificationHandler() : m_AttachedMessage(0) {}

        virtual void HandleNotification(bit32 message) = 0;
};

template <class T>
class EventNotificationHandlerBase : public NotificationHandler
{
private:
        os::LightEvent* m_pEvent;

public:
        EventNotificationHandlerBase() : m_pEvent(NULL) {}

        void Initialize(os::LightEvent* p)
        {
                NN_ASSERT_SDK_POINTER(p);
                m_pEvent = p;
        }

        virtual void HandleNotification(bit32 message)
        {
                NN_ASSERT_SDK_POINTER(m_pEvent);
                m_pEvent->Signal();
        }
};

typedef EventNotificationHandlerBase<NotificationHandler*> LightEventNotificationHandler; // 122

Result Initialize();
Result GetServiceHandle(Handle* pOut, const char8* pName, s32 length, bit32 flags);
Result RegisterNotificationHandler(NotificationHandler* pHandler, bit32 message);

inline Result ReceiveNotification(bit32* pOut) // 265
{
        detail::Service::ReceiveNotification(pOut);
}
inline Result GetServiceHandle(Handle* pOut, const char8* pName) // 308
{
        s32 length = strlen(pName);
        return GetServiceHandle(pOut, pName, length, 0);
}
inline Result TryGetServiceHandle(Handle* pOut, const char8* pName) // 319
{
        s32 length = strlen(pName);
        return GetServiceHandle(pOut, pName, length, 1);
}

} // namespace srv
} // namespace nn
