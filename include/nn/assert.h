#pragma once

#include <nn/Handle.h>
#include <nn/dbg/dbg_Break.h>

#if NN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK == 1
#define NN_ASSERT_SDK_MSG(cond, msg)                                                                      \
        if (!(cond)) {                                                                                    \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s", msg); \
        }
#define NN_ASSERT_SDK_MSGF(cond, fmt, p)                                                               \
        if (!(cond)) {                                                                                 \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, fmt, p); \
        }
#define NN_ASSERT_SDK_MIN(var, min)                                                                                                                 \
        if ((var) < (min)) {                                                                                                                        \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s(=%d) must be >= %s(=%d).", #var, var, #min, min); \
        }
#define NN_ASSERT_SDK_MAX(var, max)                                                                                                                 \
        if ((var) > (max)) {                                                                                                                        \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s(=%d) must be <= %s(=%d).", #var, var, #max, max); \
        }

#define NN_ASSERT_SDK_RESULT(cond, result)                                                                                           \
        if (!(cond)) {                                                                                                               \
                nndbgBreakWithResultMessage_ (NN_DBG_BREAK_REASON_ASSERT, (nnResult)(result), __BASE_FILE__, __LINE__, "%s", #cond); \
        }

#define NN_ASSERT_SDK(cond) NN_ASSERT_SDK_MSG (cond, #cond)

#define NN_PANIC_SDK(result)                    \
        Result nn_result_try_result = (result); \
        if (nn_result_try_result.IsFailure ())  \
        nndbgBreakWithResultMessage_ (NN_DBG_BREAK_REASON_PANIC, (nnResult)(nn_result_try_result), __BASE_FILE__, __LINE__, "\"%s\" is Failure." #result)

#else
#define NN_ASSERT_SDK_MSG(cond, msg)
#define NN_ASSERT_SDK_MSGF(cond, fmt, p)
#define NN_ASSERT_SDK_MIN(var, min)
#define NN_ASSERT_SDK_MAX(var, max)
#define NN_ASSERT_SDK_RESULT(cond, result)
#define NN_ASSERT_SDK(cond)
#define NN_PANIC_SDK(result)
#endif

#ifndef NN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK
#else
#endif
