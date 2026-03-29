#include <nn/svc/svc_StubDbg.h>

namespace nn {
namespace svc {

Result asm(Break)(nn::dbg::BreakReason reason) {
  svc 0x3c;
  bx lr;
}

Result asm(OutputDebugString)(void const *data, int length) {
  svc 0x3c;
  bx lr;
}

} // namespace svc
} // namespace nn
