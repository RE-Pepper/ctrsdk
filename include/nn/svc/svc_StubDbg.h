#pragma once

#include <nn/Result.h>
#include <nn/dbg/dbg_Enum.h>

namespace nn {
namespace svc {

Result Break (nn::dbg::BreakReason reason);
Result OutputDebugString (void const* data, int length);

} // namespace svc
} // namespace nn
