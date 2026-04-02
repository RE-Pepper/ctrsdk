#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/cfg/CTR/cfg_RegionCode.h>

namespace nn {
namespace cfg {
namespace CTR {
namespace detail {

class IpcUser
{
private:
        Handle s_Session;

public:
        Result GetConfig (void* pData, size_t size, bit32 key) const;
        Result GetRegion (CfgRegionCode*) const;
        Result GetTransferableId (bit32, bit64*);
        Result IsCoppacsSupported (bool*);
};
static_assert_ (sizeof (IpcUser) == 4);

} // namespace detail
} // namespace CTR
} // namespace cfg
} // namespace nn
