#include <nn/os/os_CriticalSection.h>

namespace nn {
namespace os {

void CriticalSection::EnterImpl ()
{
        while (true) {
                if (*m_Counter > 0 && TryEnterImpl ()) {
                        break;
                }

                m_Counter.DecrementAndWaitIfLessThan (0);
        }
}

} // namespace os
} // namespace nn
