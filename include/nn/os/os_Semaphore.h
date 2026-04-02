#pragma once

#include <nn/os/os_Synchronization.h>

namespace nn {
namespace os {

struct Semaphore : InterruptEvent
{
        Semaphore () {}
        ~Semaphore () {}

        void Acquire () { WaitOne (); }
};
static_assert_ (sizeof (Semaphore) == 0x4);

} // namespace os
} // namespace nn
