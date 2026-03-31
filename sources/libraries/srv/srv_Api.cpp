#include <nn/srv/srv_Api.h>
#include <nn/srv/srv_Service.h>

namespace nn {
namespace srv {

namespace {

static int s_InitializeCount = 0;

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

} // namespace srv
} // namespace nn
