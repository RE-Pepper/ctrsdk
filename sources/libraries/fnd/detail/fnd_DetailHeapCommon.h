#pragma once

#include <nn/fnd/detail/fnd_DetailHeapHead.h>

namespace nn {
namespace fnd {
namespace detail {

typedef ExpHeapImpl            NNSiFndHeapHead; // 96
typedef NNSiFndHeapHead*       Heap;            // 97
typedef NNSiFndHeapHead const* ConstHeap;       // 98

NNSiFndHeapHead* FindContainHeap (NNSFndList* pList, const void* memBlock);
NNSFndList*      FindListContainHeap (NNSiFndHeapHead* pHeapHd);
void             DumpHeapList ();
void             NNSi_FndFinalizeHeap (NNSiFndHeapHead* pHeapHd);
u32              GetFillValForHeap (int type);

} // namespace detail
} // namespace fnd
} // namespace nn
