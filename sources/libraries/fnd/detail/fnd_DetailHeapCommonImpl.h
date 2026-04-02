#pragma once

namespace nn {
namespace fnd {
namespace detail {

typedef u32 NNSiUIntPtr;

NNSiUIntPtr NNSiGetUIntPtr (const void* ptr)
{
        return NNSiUIntPtr (ptr);
}

} // namespace detail
} // namespace fnd
} // namespace nn
