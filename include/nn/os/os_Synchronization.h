#pragma once

#include <nn/Result.h>
#include <nn/fnd/fnd_TimeSpan.h>
#include <nn/os/CTR/os_ErrorHandler.h>
#include <nn/os/os_HandleObject.h>
#include <nn/svc/svc_Inlines.h>

namespace nn {
namespace os {

class WaitObject : public HandleObject
{
private:
        static Result WaitMultiple (s32* pOut, WaitObject** objs, s32 numHandles, bool waitAll, s64 timeout);

public:
        Result WaitOneImpl (s64 nanoSecondsTimeout)
        {
                Handle handle = GetHandle ();
                s32    dummy;
                return svc::WaitSynchronization (&dummy, &handle, 1, 0, nanoSecondsTimeout);
        }
        void WaitOne ()
        {
                NN_OS_HANDLE_ERROR (WaitOneImpl (-1));
        }
        bool WaitOne (fnd::TimeSpan timeout)
        {
                Result result = WaitOneImpl (timeout.GetNanoSeconds ());

                NN_OS_HANDLE_ERROR (result);

                return result.GetDescription () != Result::DESCRIPTION_TIMEOUT;
        }
        static s32 WaitAny (WaitObject** objs, s32 numObjects)
        {
                s32 ret;

                NN_OS_HANDLE_ERROR (WaitMultiple (&ret, objs, numObjects, false, -1));

                return ret;
        }

        WaitObject () {}
        ~WaitObject () {}
};

class InterruptEvent : public WaitObject
{
public:
        InterruptEvent () {}
        ~InterruptEvent () {}
};

} // namespace os
} // namespace nn
