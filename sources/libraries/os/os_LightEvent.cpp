#include <nn/os/os_LightEvent.h>

RP_SHUTUP

namespace nn {
namespace os {

bool LightEvent::TryWait ()
{ // 32
        if (*m_Counter == RESET_UNK1) {
                return true;
        }

        return m_Counter->CompareAndSwap (RESET_UNK0, RESET_AUTO) == RESET_UNK0;
}

void LightEvent::Wait ()
{ // 102
        while (true) {
                switch (*m_Counter) {
                case RESET_MANUAL:
                        m_Counter.WaitIfLessThan (0);
                        return;
                case RESET_UNK1:
                        return;
                case RESET_AUTO:
                        break;
                case RESET_UNK0:
                        if (m_Counter->CompareAndSwap (RESET_UNK0, RESET_AUTO) == RESET_UNK0) {
                                return;
                        }
                        break;
                }

                m_Counter.WaitIfLessThan (0);
        }
}

void LightEvent::Signal ()
{ // 135
        if (*m_Counter == RESET_AUTO) {
                *m_Counter = RESET_UNK0;
                m_Counter.Signal (1);
        } else if (*m_Counter == RESET_MANUAL) {
                *m_Counter = RESET_UNK1;
                m_Counter.SignalAll ();
        }
}

void LightEvent::Pulse ()
{
        // UNUSED
}

void LightEvent::ClearSignal ()
{ // 189
        if (*m_Counter == RESET_UNK1) {
                *m_Counter = RESET_AUTO;
        } else if (*m_Counter == RESET_UNK0) {
                *m_Counter = RESET_MANUAL;
        }
}

} // namespace os
} // namespace nn
