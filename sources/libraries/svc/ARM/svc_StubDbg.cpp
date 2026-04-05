#include <nn/svc/svc_StubDbg.h>

namespace nn {
namespace svc {

Result
asm_ext(Break, ".nn.svc.Break")(nn::dbg::BreakReason reason) {
  svc 0x3c;
  bx lr;
}

Result asm_ext(OutputDebugString, ".nn.svc.OutputDebugString")(void const *data, int length) {
  svc 0x3d;
  bx lr;
}

} // namespace svc
} // namespace nn
