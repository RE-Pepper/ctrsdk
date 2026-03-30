#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fnd/fnd_Interlocked.h>
#include <nn/os/os_Types.h>

namespace nn {
namespace os {
class WaitableCounter
{
private:
        typedef fnd::InterlockedVariable<s32> ValueType; // 36
        ValueType                             m_Value;
        static nnHandle                       s_Handle;

public:
        void Initialize ();

        ValueType& operator* () { return m_Value; }
        ValueType* operator->() { return &m_Value; }

        Result WaitIfLessThan (s32) {}
        Result Signal (s32) {}
        Result SignalAll () {}
        Result ArbitrateAddress (ArbitrationType type, s32) {}
};

} // namespace os
} // namespace nn
