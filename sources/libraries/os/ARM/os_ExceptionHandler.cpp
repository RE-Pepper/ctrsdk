#include <nn/os/ARM/os_ExceptionHandler.h>
#include <nn/os/CTR/os_ThreadLocalRegion.h>

#include "nn/assert.h"

namespace nn {
namespace os {
namespace ARM {
namespace {
var(nn:os::ARM, s_pTlr, CTR::ThreadLocalRegion*) = NULL;
}

namespace detail{
void SaveThreadLocalRegionAddress() // 31
{
        NN_ASSERT_SDK(s_pTlr == NULL); // 33
        s_pTlr = CTR::GetThreadLocalRegion();
}
}

void SetUserExceptionHandler(UserExceptionHandler pHandler, uptr stackBottom) // 38
{
        NN_ASSERT_SDK(s_pTlr != NULL); // 46

        s_pTlr->handlerAddress = (uptr)pHandler;
        s_pTlr->handlerStackBottomAddress = stackBottom;
}

} // namespace ARM
} // namespace os
} // namespace nn
