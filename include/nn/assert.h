#pragma once

#include <nn/Handle.h>
#include <nn/dbg/dbg_Break.h>

#ifndef NN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK
#define NN_ASSERT_SDK_EX(cond, msg)                                                                  \
        if (!(cond)) {                                                                               \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __FILE__, __LINE__, "%s", msg); \
        }

#define NN_PANIC_SDK(result)                    \
        Result nn_result_try_result = (result); \
        if (nn_result_try_result.IsFailure ())  \
        nndbgBreakWithResultMessage_ (NN_DBG_BREAK_REASON_PANIC, (nnresult)(nn_result_try_result), __FILE__, __LINE__, "\"%s\" is Failure." #result)

#define NN_ASSERT_SDK(cond) NN_ASSERT_SDK_EX (cond, #cond)

#else
#define NN_ASSERT_SDK_EX(cond, msg)
#define NN_ASSERT_SDK(cond)
#endif

#ifndef NN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK
#else
#endif
