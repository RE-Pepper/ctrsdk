#include <nn/cfg/CTR/cfg_Api.h>
#include <nn/cfg/CTR/cfg_DetailApi.h>

namespace nn {
namespace cfg {
namespace CTR {
namespace detail {

var(nn::cfg::CTR::detail, PORT_NAME_CFG_USER, const char* const) = "WS";

var(nn::cfg::CTR::detail, s_InitializeCount, int) = 0;
var(nn::cfg::CTR::detail, s_Initialized, bool)    = false;

Result InitializeBase(Handle* pSession, const char* name) // 34
{
        Result nn_result_try_result;
        Result result;
        // TODO
        return 0;
}

Result FinalizeBase(Handle* pSession) // 58
{
        Result nn_result_try_result;
        Result result;
        // TODO
        return 0;
}

Result Initialize() // 81
{
        Result result;
        // TODO
        return 0;
}

void Finalize() // 100
{
        // TODO
}

Result InitializeProperPort(IPCPortType* pPortType) // 117
{
        Result result;
        // TODO
        return 0;
}

void FinalizeProperPort(IPCPortType portType) // 145
{
        // TODO
}

Result GetConfig(void* pData, size_t size, bit32 key) // 164
{
        //return ::IpcUser::GetConfig(size, key);
        return 0;
}

} // namespace detail
} // namespace CTR
} // namespace cfg
} // namespace nn
