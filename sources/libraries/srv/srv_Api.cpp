#include <nn/fnd/fnd_LinkedList.h>
#include <nn/os/os_CriticalSection.h>
#include <nn/os/os_Semaphore.h>
#include <nn/srv/srv_Api.h>
#include <nn/srv/srv_Result.h>
#include <nn/srv/srv_Service.h>

namespace nn {
namespace srv {
namespace detail {
class HandlerManager
{
private:
        fnd::IntrusiveLinkedList<s32> m_Handlers; // S32 IS A PLACEHOLDER!

public:
        Result Register (NotificationHandler* pHandler, bit32)
        {
                // TODO
        }

        NotificationHandler* Unregister (bit32)
        {
                // TODO
        }

        NotificationHandler* Find (bit32)
        {
                // TODO
        }
};

struct StaticVariables
{
private:
        os::CriticalSection m_InitializeLock;
        os::Semaphore       m_NotificationSemaphore;
        //os::Thread          m_NotificationDispatcher;
        HandlerManager      m_HandlerManager;
        os::CriticalSection m_ManagerLock;
        // StackBuffer m_Stack;

public:
        StaticVariables ()
        {
                // TODO
        }
};
}

namespace {

var(nn::srv, s_InitializeCount, s32) = 0;
var(nn::srv, s_NotificationSemaphore, os::Semaphore);
var(nn::srv, s_HandlerManager, detail::HandlerManager);
//var(nn::srv, s_NotificationDispatcher, Thread);
var(nn::srv, s_InitializeLock, os::CriticalSection);
//var(nn::srv, s_Stack, StackBuffer);

} // namespace

Result GetServiceHandle (Handle* pOut, const char8* pName, s32 nameLen, bit32 flags)
{
        if (s_InitializeCount <= 0) {
                return ResultNotInitialized();
        }
        if (nameLen > 8) {
                return ResultTooLongServiceName();
        }

        Result result = detail::Service::GetServiceHandle (pOut, pName, nameLen, flags);
        // TODO: var "result", so ASSERT
        return result;
}

/*

HandlerManager::Register 40,42
HandlerManager::Find 65

anon DispatcherThread 111

Initialize 167
GetServiceHandle 368

*/

} // namespace srv
} // namespace nn
