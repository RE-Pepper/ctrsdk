#pragma once

namespace nn {
namespace os {

enum MemoryState
{
        MEMORY_STATE_FREE       = 0,
        MEMORY_STATE_RESERVED   = 1,
        MEMORY_STATE_IO         = 2,
        MEMORY_STATE_STATIC     = 3,
        MEMORY_STATE_CODE       = 4,
        MEMORY_STATE_PRIVATE    = 5,
        MEMORY_STATE_SHARED     = 6,
        MEMORY_STATE_CONTINUOUS = 7,
        MEMORY_STATE_ALIASED    = 8,
        MEMORY_STATE_ALIAS      = 9,
        MEMORY_STATE_ALIAS_CODE = 10,
        MEMORY_STATE_LOCKED     = 11,
        MEMORY_STATE_MAX_BITS   = 2147483648,
};

} // namespace os
} // namespace nn
