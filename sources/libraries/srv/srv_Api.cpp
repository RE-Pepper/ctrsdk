#include <nn/os/os_CriticalSection.h>
#include <nn/srv/srv_Api.h>
#include <nn/srv/srv_Service.h>

namespace nn {
namespace srv {

namespace {

var(nn::srv, s_InitializeCount, s32) = 0;
//var(nn::srv, s_NotificationSemaphore, Semaphore);
//var(nn::srv, s_HandlerManager, HandlerManager);
//var(nn::srv, s_NotificationDispatcher, Thread);
var(nn::srv, s_InitializeLock, os::CriticalSection);
//var(nn::srv, s_Stack, StackBuffer);

} // namespace

#ifdef NON_MATCHING
Result GetServiceHandle (Handle* pOut, const char* pName, s32 nameLen, bit32 flags)
{
        if (s_InitializeCount > 0) {
                return Result (Result::LEVEL_PERMANENT, Result::SUMMARY_INVALID_STATE, Result::MODULE_NN_SRV, 1016);
        }
        if (nameLen > 8) {
                return Result (Result::LEVEL_PERMANENT, Result::SUMMARY_WRONG_ARGUMENT, Result::MODULE_NN_SRV, 5);
        }

        return detail::Service::GetServiceHandle (pOut, pName, nameLen, flags);
}
#endif

/*

HandlerManager::Register 40,42
HandlerManager::Find 65

anon DispatcherThread 111

Initialize 167
GetServiceHandle 368

*/

} // namespace srv
} // namespace nn
