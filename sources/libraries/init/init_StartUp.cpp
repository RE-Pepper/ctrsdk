#include <nn/init/init_StartUp.h>

RP_SHUTUP

extern "C" void nninitSystem () // 43
{
        // nn::os::Initialize();
#if 0
        // nn::srv::Initialize();
#endif
}

extern "C" void nninitSetupDaemons () // 55
{
        // nn::ndm::SetupDaemonsDefault();
}

extern "C" nninitStaticInitFunc Image$$STATIC_INIT$$RO$$Base[];
extern "C" nninitStaticInitFunc Image$$STATIC_INIT$$RO$$Limit[];

extern "C" void nninitCallStaticInitializers () // 62
{
        for (nninitStaticInitFunc* f = Image$$STATIC_INIT$$RO$$Base;
                f < Image$$STATIC_INIT$$RO$$Limit;
                ++f) {
                (*f) ();
        }
}

extern "C" void nninitSetup () // 72
{
        /*
        nninitSetupDefault();
        nn::os::CTR::defaul::SetInternalErrorHandlingMode(0); // TODO MACRO
        nn::applet::CTR::detaul::Initialize(0); // TODO MACRO
        nninitSetupDaemons();
        */
}
