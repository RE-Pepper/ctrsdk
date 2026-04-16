#include <nn/fnd/fnd_LinkedList.h>
#include <nn/os/os_CriticalSection.h>
#include <nn/os/os_Semaphore.h>
#include <nn/os/os_Thread.h>
#include <nn/srv/srv_Api.h>
#include <nn/srv/srv_Result.h>
#include <nn/srv/srv_Service.h>

#include "nn/Result.h"
#include "nn/assert.h"

namespace nn {
namespace srv {
namespace detail {

class HandlerManager
{
private:
        fnd::IntrusiveLinkedList<NotificationHandler> m_Handlers;

public:
        inline Result Register(NotificationHandler* pHandler, bit32 message)
        {
                NN_ASSERT_SDK_POINTER(pHandler);                 // 40
                NN_ASSERT_SDK(message != 0);                     // 41
                NN_ASSERT_SDK(pHandler->m_AttachedMessage == 0); // 42

                pHandler->m_AttachedMessage = message;
                m_Handlers.PushBack(pHandler);

                return ResultSuccess();
        }

        inline NotificationHandler* Unregister(bit32 message)
        {
                NN_ASSERT_SDK(message != 0);

                NotificationHandler* p = Find(message);
                if (p != NULL) {
                        m_Handlers.Erase(p);
                        p->m_AttachedMessage = 0;
                }

                return p;
        }

        inline NotificationHandler* Find(bit32 message)
        {
                NN_ASSERT_SDK(message != 0); // 65
                for (NotificationHandler* i = m_Handlers.GetFront(); i && i->m_AttachedMessage != message; i = m_Handlers.GetFront())
                        ;
        }
};

struct StaticVariables
{
        os::CriticalSection  m_InitializeLock;
        os::Semaphore        m_NotificationSemaphore;
        os::Thread           m_NotificationDispatcher;
        HandlerManager       m_HandlerManager;
        os::CriticalSection  m_ManagerLock;
        os::StackBuffer<512> m_Stack; // 1024 in some debug ver, TODO check
};
}

namespace {

var(nn::srv, s_InitializeCount, s32) = 0;
var(nn::srv, s_NotificationSemaphore, os::Semaphore);
var(nn::srv, s_HandlerManager, detail::HandlerManager);
var(nn::srv, s_NotificationDispatcher, os::Thread);
var(nn::srv, s_InitializeLock, os::CriticalSection);
var(nn::srv, s_Stack, os::StackBuffer<512>);

} // namespace

/*

...RegisterNotificationHandler?

anon DispatcherThread 111

Initialize 167
Finalite 183,193
*/

Result RegisterNotificationHandler(NotificationHandler* pHandler, bit32 message)
{ // 303
    return s_HandlerManager.Register(pHandler, message);
}

Result GetServiceHandle (Handle* pOut, const char8* pName, s32 nameLen, bit32 flags)
{ // 357
        if (s_InitializeCount <= 0) {
                return ResultNotInitialized();
        }
        if (nameLen > 8) {
                return ResultTooLongServiceName();
        }

        Result result = detail::Service::GetServiceHandle (pOut, pName, nameLen, flags);
        NN_ASSERT_SDK_WARN_RESULT(result, "Failed to open service \"%s\"\n", pName); // 368
        return result;
}

} // namespace srv
} // namespace nn
