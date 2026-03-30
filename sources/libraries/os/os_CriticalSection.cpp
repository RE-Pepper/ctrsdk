#include <nn/os/os_CriticalSection.h>

namespace nn {
namespace os {

void CriticalSection::EnterImpl ()
{
        while (true) {
                if (*m_Counter > 0) {
                        if (TryEnterImpl ()) {
                                break;
                        }
                }
        }
}

} // namespace os
} // namespace nn
