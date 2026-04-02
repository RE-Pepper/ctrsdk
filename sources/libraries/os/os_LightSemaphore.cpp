#include <nn/os/os_LightSemaphore.h>

#include "nn/assert.h"

namespace nn {
namespace os {

RP_SHUTUP

s32 LightSemaphore::Release (s32 releaseCount)
{
        NN_ASSERT_SDK_MAX (releaseCount, 1); // 24
        // TODO
}

} // namespace os
} // namespace nn
