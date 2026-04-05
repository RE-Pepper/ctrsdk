#pragma once

#include <nn/Handle.h>
#include <nn/os/os_WaitableCounter.h>
#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace os {

class LightEvent : util::ADLFireWall::NonCopyable<LightEvent>
{
private:
        WaitableCounter m_Counter;

        static const s32 RESET_MANUAL = -2;
        static const s32 RESET_AUTO   = -1;
        static const s32 RESET_UNK0   = 0;
        static const s32 RESET_UNK1   = 1;

public:
        void Initialize (bool isManualReset) // 25
        {
                *m_Counter = isManualReset ? RESET_MANUAL : RESET_AUTO;
        }
        void Finalize () {}

        LightEvent () {}                                                // 77
        LightEvent (bool isManualReset) { Initialize (isManualReset); } // 103

        bool IsSignaled () { return *m_Counter >= 0; }
        bool IsManualReset ()
        {
                return *m_Counter == RESET_MANUAL;
        }

        bool TryWait ();
        void Wait ();
        void Signal ();
        void Pulse ();
        void ClearSignal ();
};

} // namespace os
} // namespace nn

#ifdef __cplusplus
extern "C" {
#endif

typedef union nnosLightEvent {
} nnosLightEvent;

// nnos..(); come here

#ifdef __cplusplus
}
#endif
