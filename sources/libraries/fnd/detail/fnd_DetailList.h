#include <nn/fnd/detail/fnd_DetailHeapHead.h>

namespace nn {
namespace fnd {
namespace detail {

void RemoveListObject (NNSFndList* list, void* object);

void* GetNextListObject (NNSFndList* list, void* object);

} // namespace detail
} // namespace fnd
} // namespace nn
