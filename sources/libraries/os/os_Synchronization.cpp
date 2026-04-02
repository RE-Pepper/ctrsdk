#include <nn/os/os_Synchronization.h>

RP_SHUTUP

namespace nn {
namespace os {

namespace {

struct WaitMultipleObjectsArgs
{
        s32*         pOut;
        WaitObject** objs;
        s32          numHandles;
        bool         waitAll;
        s64*         timeout;
};

Result WaitMultipleImpl (WaitMultipleObjectsArgs* args, Handle* handles)
{
        // TODO
}

void asm (WaitMultipleImplWithAlloca) (WaitMultipleObjectsArgs* args, int, Result (*) (WaitMultipleObjectsArgs*, nn::Handle*))
{
        push  { lr }; // nf
        bics  r3, r1, #1;
        addne r1, r1, #1;
        mov   r3, r1, lsl #2;
        sub   sp, sp, r3;
        mov   r1, sp;
        push { r3 }; // nf
        blx   r2;
        pop { r3 }; // nf
        add   sp, sp, r3;
        pop { pc }; // nf
}
} // namespace

} // namespace os
} // namespace nn
