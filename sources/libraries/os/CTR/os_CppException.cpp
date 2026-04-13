#include <cstdlib>
#include <exception>
#include <nn/os/CTR/os_CppException.h>
#include <nn/os/CTR/os_ThreadLocalRegion.h>

namespace nn {
namespace os {
namespace CTR {

namespace {

extern "C" __weak void __ARM_exceptions_buffer_required(void);
extern "C" void*       __ARM_exceptions_buffer_init(void);

typedef void (*handler)(); // 28

struct __cxa_eh_globals
{
        uint32_t                uncaughtExceptions;
        std::unexpected_handler unexpectedHandler;
        std::terminate_handler  terminateHandler;
        bool                    implementation_ever_called_terminate;
        handler                 call_hook;
        void*                   caughtExceptions;
        void*                   propagatingExceptions;
        void*                   emergency_buffer;
};

bool IsArmExceptionsBufferNotRequired() // 44
{
        return &__ARM_exceptions_buffer_required == NULL;
}

} // namespace

void force_func_section(_ZN2nn2os3CTR43_GLOBAL__N__19_os_CppException_cpp_0201818f23DefaultTerminateHandlerEv) DefaultTerminateHandler() // 49
{
        std::abort();
}

void force_func_section(_ZN2nn2os3CTR43_GLOBAL__N__19_os_CppException_cpp_0201818f24DefaultUnexpectedHandlerEv) DefaultUnexpectedHandler() // 53
{
        std::terminate();
}

void SetupThreadCppExceptionEnvironment() // 60
{
        ThreadLocalRegion* pTlr = GetThreadLocalRegion(); // 62

        pTlr->ehGlobalsAddr = pTlr->ehGlobals;

        // The DWARF and assembly show ehGlobals is at an offset within TLR (likely 0x60)
        __cxa_eh_globals& ceg = *reinterpret_cast<__cxa_eh_globals*>(pTlr->ehGlobals);

        ceg.uncaughtExceptions                   = 0;
        ceg.unexpectedHandler                    = DefaultUnexpectedHandler;
        ceg.terminateHandler                     = DefaultTerminateHandler;
        ceg.implementation_ever_called_terminate = false;
        ceg.call_hook                            = NULL;
        ceg.caughtExceptions                     = NULL;
        ceg.propagatingExceptions                = NULL;
        ceg.emergency_buffer                     = IsArmExceptionsBufferNotRequired() ? NULL : __ARM_exceptions_buffer_init();
}

} // namespace CTR
} // namespace os
} // namespace nn
