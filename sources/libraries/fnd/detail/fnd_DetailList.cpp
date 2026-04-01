#pragma once

#include "./fnd_DetailList.h"

#include <nn/assert.h>

namespace nn {
namespace fnd {
namespace detail {

void RemoveListObject (NNSFndList* list, void* object) // 196
{
        NN_ASSERT_SDK_MSG (list, "list");     // 200
        NN_ASSERT_SDK_MSG (object, "object"); // 201
        NNSFndLink* link;
        // TODO
}
void* GetNextListObject (NNSFndList* list, void* object) // 240
{
        NN_ASSERT_SDK_MSG (list, "list"); // 242
        if (object == NULL) {
                return list->headObject;
        }
        return ((NNSFndLink*)(u32)object + list->offset)->nextObject;
}

} // namespace detail
} // namespace fnd
} // namespace nn
