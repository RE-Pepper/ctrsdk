#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fnd/fnd_Interlocked.h>
#include <nn/os/os_Types.h>
#include <nn/svc/svc_Stub.h>

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
        void Finalize ();

        ValueType& operator* () { return m_Value; }
        ValueType* operator->() { return &m_Value; }

        Result ArbitrateAddress (ArbitrationType type, s32 value)
        {
                return svc::ArbitrateAddress (s_Handle, (uptr)&m_Value, type, value);
        }
        Result WaitIfLessThan (s32 value)
        {
                return ArbitrateAddress (ARBITRATION_TYPE_WAIT_IF_LESS_THAN, value);
        }
        Result WaitIfLessThanWithTimeout (s32 value)
        {
                return ArbitrateAddress (ARBITRATION_TYPE_WAIT_IF_LESS_THAN_WITH_TIMEOUT, value);
        }
        Result DecrementAndWaitIfLessThan (s32 value)
        {
                return ArbitrateAddress (ARBITRATION_TYPE_DECREMENT_AND_WAIT_IF_LESS_THAN, value);
        }
        Result DecrementAndWaitIfLessThanWithTimeout (s32 value)
        {
                return ArbitrateAddress (ARBITRATION_TYPE_DECREMENT_AND_WAIT_IF_LESS_THAN_WITH_TIMEOUT, value);
        }
        Result Signal (s32 value)
        {
                return ArbitrateAddress (ARBITRATION_TYPE_SIGNAL, value);
        }
        Result SignalAll ()
        {
                return Signal (-1);
        }
};

} // namespace os
} // namespace nn
