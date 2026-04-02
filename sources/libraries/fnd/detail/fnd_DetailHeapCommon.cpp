#include "./fnd_DetailHeapCommon.h"

#include "./fnd_DetailHeapCommonImpl.h"
#include "./fnd_DetailList.h"
#include "nn/assert.h"

RP_SHUTUP

namespace nn {
namespace fnd {
namespace detail {
#define NN_OS_HEAP_FILL_MAX 3

var (nn::fnd::detail, sRootList, NNSFndList);
var(nn::fnd::detail, sRootListInitialized, bool) = false;

var(nn::fnd::detail, sFillVals, u32)[NN_OS_HEAP_FILL_MAX] = {
    0xC3C3C3C3,
    0xF3F3F3F3,
    0xD3D3D3D3
};

NNSiFndHeapHead* FindContainHeap (NNSFndList* pList, const void* memBlock) // 76
{
        NNSiFndHeapHead* pHeapHd = NULL;
        while ( (pHeapHd = (NNSiFndHeapHead*)GetNextListObject(pList, pHeapHd)) != NULL) {
                if (NNSiGetUIntPtr(pHeapHd->heapStart) <= NNSiGetUIntPtr(memBlock) 
                    && NNSiGetUIntPtr(memBlock) < NNSiGetUIntPtr(pHeapHd->heapEnd)) {
                        NNSiFndHeapHead* pChildHeapHd = FindContainHeap(&pHeapHd->childList, memBlock);
                        if(pChildHeapHd)
                        {
                                return pChildHeapHd;
                        }
                        return pHeapHd;
                }
        }

        return NULL;
}

NNSFndList* FindListContainHeap (NNSiFndHeapHead* pHeapHd) // 115
{
        NNSFndList*      pList = &sRootList;
        NNSiFndHeapHead* pContainHeap = FindContainHeap(&sRootList, pHeapHd);
        if (pContainHeap != NULL) {
            pList = &pContainHeap->childList;
        }
        return pList;
}

void DumpHeapList () // 132
{}

void NNSi_FndFinalizeHeap (NNSiFndHeapHead* pHeapHd) // 212
{
        RemoveListObject(FindListContainHeap(pHeapHd), pHeapHd);
        DumpHeapList();
}

u32 GetFillValForHeap (int type)
{
        NN_ASSERT_SDK(type < NN_OS_HEAP_FILL_MAX);
        return sFillVals[type];
}

} // namespace detail
} // namespace fnd
} // namespace nn
