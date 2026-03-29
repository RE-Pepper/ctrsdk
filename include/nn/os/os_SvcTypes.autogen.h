#pragma once

#include <nn/os/os_MemoryTypes.h>

namespace nn {
namespace os {

typedef void (*ThreadFunc)(uptr); // 37

struct MemoryInfo
{
        uptr        baseAddress;
        size_t      size;
        bit32       permission;
        MemoryState state;
};

struct PageInfo
{
        bit32 flags;
};

} // namespace os
} // namespace nn
