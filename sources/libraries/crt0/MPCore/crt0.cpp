#include <nn/init/init_StartUp.h>
#include <nn/module.h>
#include <nn/svc/svc_Stub.h>
#include <rt_locale.h>
#include <rt_sys.h>

namespace {
NN_MAKE_MODULE_SDK(s_DebugIndicator, "DEBUG");
NN_MAKE_MODULE_SDK(s_SdkVersion, "CTR_SDK-2_4_1_200_none");
NN_MAKE_MODULE_SDK(s_FirmwareVersion, "Firmware-02_30_20");
} // namespace

extern "C" void nninitRegion();
extern "C" void nninitStartUp();
extern "C" void nninitLocale();

extern "C" __weak void __cpp_initialize__aeabi_();
extern "C" u32*        __rt_locale(void);

extern "C" void nnMain();

extern "C" u8 Image$$ZI$$ZI$$Base[];
extern "C" u8 Image$$ZI$$ZI$$Limit[];

extern "C" void __asm __ctr_start()
{
        bl  __cpp(nninitRegion);
        bl  __cpp(nninitLocale);
        bl  __cpp(nninitSystem);
        bl  __cpp(nninitStartUp);
        blx __cpp(__cpp_initialize__aeabi_);
        bl  __cpp(nninitCallStaticInitializers);
        bl  __cpp(nninitSetup);
        blx __cpp(nnMain);
        b   __cpp(nn::svc::ExitProcess);
}

extern "C" void nninitLocale()
{
#if 0
        NN_REFER_MODULE(s_DebugIndicator);
#endif
        NN_REFER_MODULE(s_SdkVersion);
        NN_REFER_MODULE(s_FirmwareVersion);

        u32* rt   = __rt_locale();
        *(rt + 1) = (u32)_get_lc_ctype(0, 0) + 1;
        *(rt + 3) = (u32)_get_lc_numeric(0, 0);
}

extern "C" void asm(nninitRegion)()
{
        ldr   r0, = __cpp(Image$$ZI$$ZI$$Base);
        ldr   r1, = __cpp(Image$$ZI$$ZI$$Limit);
        mov   r2, #0;

run // nf
        cmp   r0, r1; // nf
        strcc r2, [r0], #4;
        bcc   run;
        bx    lr;
}
// clang-format on

