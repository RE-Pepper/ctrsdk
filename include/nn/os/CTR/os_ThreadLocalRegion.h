#pragma once

namespace nn {
namespace os {
namespace CTR {

struct ThreadLocalRegion
{
        uptr  tls[16];
        uptr  handlerAddress;
        uptr  handlerStackBottomAddress;
        bit8  reserved[20];
        bit32 ehGlobalsAddr;
        bit32 ehGlobals[8];
        bit32 messageBuffer[64];
        bit32 receiveBuffer[32];
};

static_assert_(sizeof(ThreadLocalRegion) == 0x200);

inline ThreadLocalRegion* GetThreadLocalRegion()
{
        ThreadLocalRegion* p;
        __asm { MRC p15, 0, p,c13,c0, 3 }
        return p;
}

} // namespace CTR
} // namespace os
} // namespace nn
