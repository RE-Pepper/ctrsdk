#pragma once
#include "./fnd_DetailHeapCommon.h"

namespace nn {
namespace fnd {
namespace detail {

bool IsValidHeapHandle (ConstHeap handle);

void DestroyHeap (Heap heap);

} // namespace detail
} // namespace fnd
} // namespace nn
