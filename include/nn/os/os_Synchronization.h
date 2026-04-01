#pragma once

#include <nn/Result.h>
#include <nn/fnd/fnd_TimeSpan.h>
#include <nn/os/os_HandleObject.h>

namespace nn {
namespace os {

class WaitObject : HandleObject
{
private:
        static Result WaitMultiple (s32, bool, s64);

public:
        void       WaitOne ();
        bool       WaitOne (fnd::TimeSpan);
        static s32 WaitAny (fnd::TimeSpan);

protected:
        WaitObject ();
        ~WaitObject ();
};

class InterruptEvent : WaitObject
{
};

} // namespace os
} // namespace nn
