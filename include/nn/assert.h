#pragma once

#include <nn/Handle.h>
#include <nn/dbg/dbg_Break.h>

#ifndef NN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK
#define NN_ASSERT_SDK_MSG(cond, msg)                                                                 \
        if (!(cond)) {                                                                               \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __FILE__, __LINE__, "%s", msg); \
        }
#define NN_ASSERT_SDK_MSGF(cond, fmt, p)                                                          \
        if (!(cond)) {                                                                            \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __FILE__, __LINE__, fmt, p); \
        }

#define NN_ASSERT_SDK_RESULT(cond, result)                                                                                      \
        if (!(cond)) {                                                                                                          \
                nndbgBreakWithResultMessage_ (NN_DBG_BREAK_REASON_ASSERT, (nnResult)(result), __FILE__, __LINE__, "%s", #cond); \
        }

#define NN_ASSERT_SDK(cond) NN_ASSERT_SDK_MSG (cond, #cond)

#define NN_PANIC_SDK(result)                    \
        Result nn_result_try_result = (result); \
        if (nn_result_try_result.IsFailure ())  \
        nndbgBreakWithResultMessage_ (NN_DBG_BREAK_REASON_PANIC, (nnResult)(nn_result_try_result), __FILE__, __LINE__, "\"%s\" is Failure." #result)

#else
#define NN_ASSERT_SDK_MSG(cond, msg)
#define NN_ASSERT_SDK_MSGF(cond, fmt, p)
#define NN_ASSERT_SDK_RESULT(cond, result)
#define NN_ASSERT_SDK(cond)
#define NN_PANIC_SDK(result)
#endif

#ifndef NN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK
#else
#endif
