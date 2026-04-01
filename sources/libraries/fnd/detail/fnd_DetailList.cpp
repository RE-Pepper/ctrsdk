#pragma once

#include "./fnd_DetailList.h"

#include <nn/assert.h>

namespace nn {
namespace fnd {
namespace detail {

void RemoveListObject (NNSFndList* list, void* object) // 196
{
        NN_ASSERT_SDK (list);   // 200
        NN_ASSERT_SDK (object); // 201

        NNSFndLink* link = (NNSFndLink*)((u32)object + list->offset);
        if (link->prevObject == NULL) {
                list->headObject = link->nextObject;
        } else {
                ((NNSFndLink*)((u32)link->prevObject + list->offset))->nextObject = link->nextObject;
        }
        if (link->nextObject == NULL) {
                list->tailObject = link->prevObject;
        } else {
                ((NNSFndLink*)((u32)link->nextObject + list->offset))->prevObject = link->prevObject;
        }

        link->nextObject = link->prevObject = NULL;
        --list->numObjects;
}

void* GetNextListObject (const NNSFndList* list, const void* object) // 240
{
        NN_ASSERT_SDK (list); // 242
        if (object == NULL) {
                return list->headObject;
        }
        return ((NNSFndLink*)(u32)object + list->offset)->nextObject;
}

} // namespace detail
} // namespace fnd
} // namespace nn
