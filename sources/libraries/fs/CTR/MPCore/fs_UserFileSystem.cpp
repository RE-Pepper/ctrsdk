#include <nn/fs/CTR/MPCore/fs_UserFileSystem.h>

RP_SHUTUP

namespace nn {
namespace fs {
namespace CTR {
namespace MPCore {
namespace detail {

namespace {
var(nn::fs::CTR::MPCore::detail, g_FileServerHandle, Handle);
} // namespace

var(nn::fs::CTR::MPCore::detail, s_IsLatencyEmulationEnable, bool) = false;
} // namespace detail
} // namespace MPCore
} // namespace CTR

void ForceDisableLatencyEmulation()
{
        CTR::MPCore::detail::s_IsLatencyEmulationEnable = false;
}

} // namespace fs
} // namespace nn
