#include <nn/assert.h>
#include <nn/os/os_WaitableCounter.h>
#include <nn/svc/svc_Stub.h>

namespace nn {
namespace os {

nnHandle WaitableCounter::s_Handle = { 0 };

void WaitableCounter::Initialize ()
{
        if (s_Handle.value == INVALID_HANDLE_VALUE.value) {
                Handle h;
                Result ret = svc::CreateAddressArbiter (&h);
                NN_ASSERT_SDK (ret.IsSuccess ());
                if (ret.IsSuccess ()) {
                        s_Handle = h;
                }
        }
}
void WaitableCounter::Finalize ()
{
        // UNUSED
}

} // namespace os
} // namespace nn
