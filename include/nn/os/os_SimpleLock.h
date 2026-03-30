#pragma once

#include <nn/os/os_WaitableCounter.h>
#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace os {

class SimpleLock : nn::util::ADLFireWall::NonCopyable<SimpleLock>
{
        WaitableCounter m_Counter;

public:
        SimpleLock ();
        ~SimpleLock ();
};

} // namespace os
} // namespace nn
