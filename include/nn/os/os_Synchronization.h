#pragma once

#include <nn/Result.h>
#include <nn/fnd/fnd_TimeSpan.h>
#include <nn/os/os_HandleObject.h>

namespace nn {
namespace os {

class WaitObject : nn::os::HandleObject
{
public:
        void       WaitOne();
        bool       WaitOne(nn::fnd::TimeSpan);
        static s32 WaitAny(nn::fnd::TimeSpan);

protected:
        WaitObject();
        ~WaitObject();

private:
        static nn::Result WaitMultiple(s32, bool, s64);
};

} // namespace os
} // namespace nn
