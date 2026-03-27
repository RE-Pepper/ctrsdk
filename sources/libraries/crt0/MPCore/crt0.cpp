#include <nn/svc/svc_Api.h>
#include <rt_locale.h>
#include <rt_sys.h>

extern "C" {
void nninitRegion();
void nninitLocale();
void nninitSystem();
void nninitStartUp();

__weak void   __cpp_initialize__aeabi_();
u32* __rt_locale( void );

void nninitCallStaticInitializers();
void nninitSetup();
void nnMain();

extern u8 Image$$ZI$$ZI$$Base[];
extern u8 Image$$ZI$$ZI$$Limit[];

void asm(__ctr_start)()
{
        // clang-format off
    bl __cpp(nninitRegion)
    bl __cpp(nninitLocale)
    bl __cpp(nninitSystem)
    bl __cpp(nninitStartUp)
    bl __cpp(__cpp_initialize__aeabi_)
    bl __cpp(nninitCallStaticInitializers)
    bl __cpp(nninitSetup)
    bl __cpp(nnMain)
    b __cpp(nn::svc::ExitProcess)
        // clang-format on
}

void asm(nninitRegion)()
{
        // clang-format off
    ldr r0, =__cpp(Image$$ZI$$ZI$$Base)
    ldr r1, =__cpp(Image$$ZI$$ZI$$Limit)
    mov r2, #0
run
    cmp r0, r1
    strcc r2, [r0], #4
    bcc run
    bx lr
        // clang-format on
}

void nninitLocale()
{
        u32* rt = __rt_locale();
        *( rt + 1 )      = (u32)_get_lc_ctype( 0, 0 ) + 1;
        *( rt + 3 )      = (u32)_get_lc_numeric( 0, 0 );
}
// clang-format on

}
