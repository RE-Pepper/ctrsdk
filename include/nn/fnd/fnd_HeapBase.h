#pragma once

#include <nn/fnd/fnd_LinkedList.h>

namespace nn {
namespace fnd {

enum HeapFillType
{
        HEAP_FILL_TYPE_NOUSE,
        HEAP_FILL_TYPE_ALLOC,
        HEAP_FILL_TYPE_FREE,
        HEAP_FILL_TYPE_MAX
};

class HeapBase : IntrusiveLinkedList<HeapBase>::Item
{
private:
        HeapBase*                     m_Parent;
        IntrusiveLinkedList<HeapBase> m_Children;
        bit32                         m_Option;

public:
        u32 GetFillValue (HeapFillType);
        ~HeapBase ();

        void Initialize (bit32 option);

        HeapBase* GetRoot ();
        HeapBase* FindHeap (void*);
        void      Destroy (HeapBase*);
        void      SetParent (HeapBase*);

        static uptr RoundDown (uptr, s32);
        static uptr RoundUp (uptr, s32);

        void FillMemoryZero (uptr, size_t size);

#if 0 // TODO: DEBUG MACRO
        void DebugFillMemory(uptr, size_t, HeapFillType) {}
#else
        void DebugFillMemory (uptr, size_t, HeapFillType) {}

        static void FillMemory (uptr, uptr, bit8);
        static void FillMemory32 (uptr, uptr, bit8);
#endif
};

} // namespace fnd
} // namespace nn
