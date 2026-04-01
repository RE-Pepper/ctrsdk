#include <nn/fs/CTR/MPCore/fs_UserFileSystem.h>

RP_SHUTUP

namespace nn {
namespace fs {
namespace CTR {
namespace MPCore {
namespace detail {

namespace {
var(Handle, g_FileServerHandle);
} // namespace

var(bool, s_IsLatencyEmulationEnable) = false;
} // namespace detail
} // namespace MPCore
} // namespace CTR

void ForceDisableLatencyEmulation()
{
        CTR::MPCore::detail::s_IsLatencyEmulationEnable = false;
}

} // namespace fs
} // namespace nn
