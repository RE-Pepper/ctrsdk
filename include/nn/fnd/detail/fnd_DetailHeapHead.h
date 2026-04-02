#pragma once

namespace nn {
namespace fnd {
namespace detail {

typedef struct
{
        void* prevObject;
        void* nextObject;
} NNSFndLink;
static_assert_ (sizeof (NNSFndLink) == 0x8);

typedef struct
{
        void* headObject;
        void* tailObject;
        u16   numObjects;
        u16   offset;
} NNSFndList;
static_assert_ (sizeof (NNSFndList) == 0xC);

struct NNSiFndExpHeapMBlockHead
{
        u16                       signature;
        u16                       attribute;
        u32                       blockSize;
        NNSiFndExpHeapMBlockHead* pMBHeadPrev;
        NNSiFndExpHeapMBlockHead* pMBHeadBext;
};
static_assert_ (sizeof (NNSiFndExpHeapMBlockHead) == 0x10);

struct NNSiFndExpMBlockList
{
        NNSiFndExpHeapMBlockHead* head;
        NNSiFndExpHeapMBlockHead* tail;
};
static_assert_ (sizeof (NNSiFndExpMBlockList) == 0x8);

struct NNSiFndExpHeapHead
{
        NNSiFndExpMBlockList mbFreeList;
        NNSiFndExpMBlockList mbUsedList;
        u16                  groupID;
        u16                  feature;
        bool                 reuse;
        u32 : 24;
};
static_assert_ (sizeof (NNSiFndExpHeapHead) == 0x18);

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
static_assert_ (sizeof (ExpHeapImpl) == 0x3C);

} // namespace detail
} // namespace fnd
} // namespace nn
