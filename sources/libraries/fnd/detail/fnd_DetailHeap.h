#pragma once
#include "./fnd_DetailHeapCommon.h"
#include "./fnd_DetailHeapCommonImpl.h"

namespace nn {
namespace fnd {
namespace detail {

#define NN_HEAP_EXP_IDENT (int)'EXPH'

bool IsValidHeapHandle (ConstHeap handle);

NNSiUIntPtr NNSiGetUIntPtr (void* ptr);

void DestroyHeap (Heap heap);

} // namespace detail
} // namespace fnd
} // namespace nn
