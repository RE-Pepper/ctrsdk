#include "./fnd_DetailHeapCommon.h"

#include "./fnd_DetailList.h"

RP_SHUTUP

namespace nn {
namespace fnd {
namespace detail {

var(NNSFndList, sRootList);
var(bool, sRootListInitialized) = false;

var(u32, sFillVals[3]) = {
    0xC3C3C3C3, // Initial
    0xF3F3F3F3, // Allocated
    0xD3D3D3D3  // Destroyed
};

NNSiFndHeapHead* FindContainHeap (NNSFndList* pList, const void* memBlock) // 76
{
        for(NNSiFndHeapHead* pHeapHd = NULL; GetNextListObject(pList, pHeapHd) != NULL; pHeapHd = (NNSiFndHeapHead*)GetNextListObject(pList, pHeapHd)) {
            // TODO
        }
        NNSiFndHeapHead pChildHeapHd;
        // TODO
}

NNSFndList* FindListContainHeap (NNSiFndHeapHead* pHeapHd) // 115
{
        NNSFndList*      pList;
        NNSiFndHeapHead* pContainHeap;
        // TODO
}

void DumpHeapList () // 132
{
        // TODO
}

void NNSi_FndFinalizeHeap (NNSiFndHeapHead* pHeapHd) // 212
{
        // TODO
}

u32 GetFillValForHeap (int type)
{
        // TODO
}

} // namespace detail
} // namespace fnd
} // namespace nn
