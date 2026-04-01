#include "./fnd_DetailHeap.h"

#include <nn/assert.h>

#include "fnd_DetailHeapCommon.h"

namespace nn {
namespace fnd {
namespace detail {

bool IsValidHeapHandle (ConstHeap handle) // 103
{
        if (handle == NULL) {
                return false;
        }

        ConstHeap pHeapHd = handle;
        return (pHeapHd->signature == NN_HEAP_EXP_IDENT);
}

NNSiUIntPtr NNSiGetUIntPtr (void* ptr) // 116
{
        return (NNSiUIntPtr)ptr;
}

void DestroyHeap (Heap heap) // 1258 (yes one thousand)
{
        NN_ASSERT_SDK (IsValidHeapHandle (heap));
        NNSi_FndFinalizeHeap (heap);
}

} // namespace detail
} // namespace fnd
} // namespace nn

