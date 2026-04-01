#pragma once

namespace nn {
namespace fnd {
namespace detail {

typedef struct
{
        void* prevObject;
        void* nextObject;
} NNSFndLink;

typedef struct
{
        void* headObject;
        void* tailObject;
        u16   numObjects;
        u16   offset;
} NNSFndList;

struct NNSiFndExpHeapMBlockHead
{
        u16                       signature;
        u16                       attribute;
        u32                       blockSize;
        NNSiFndExpHeapMBlockHead* pMBHeadPrev;
        NNSiFndExpHeapMBlockHead* pMBHeadBext;
};
struct NNSiFndExpMBlockList
{
        NNSiFndExpHeapMBlockHead* head;
        NNSiFndExpHeapMBlockHead* tail;
};
struct NNSiFndExpHeapHead
{
        NNSiFndExpMBlockList* mbFreeList;
        NNSiFndExpMBlockList* mbUsedList;
        u16                   groupID;
        u16                   feature;
        bool                  reuse;
        int                   unk; // unnamed int?
};

struct ExpHeapImpl
{
        u32                signature;
        NNSFndLink         link;
        NNSFndList         childList;
        void*              heapStart;
        void*              heapEnd;
        u32                attribute;
        NNSiFndExpHeapHead nnsiFndExpHeapHead;

        ExpHeapImpl () : attribute (0) {}
};

} // namespace detail
} // namespace fnd
} // namespace nn
