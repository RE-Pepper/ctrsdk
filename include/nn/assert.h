#pragma once

#include <nn/Handle.h>
#include <nn/dbg/dbg_Break.h>
#include <nn/dbg/dbg_DebugString.h>

#if NN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK == 0
#define NN_ASSERT_SDK(cond)                                                                                \
        if (!(cond)) {                                                                                     \
                nndbgBreakWithTMessage_(NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s", #cond); \
        }
#define NN_ASSERT_SDK_MSG(cond, ...)                                                                       \
        if (!(cond)) {                                                                                     \
                nndbgBreakWithTMessage_(NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, __VA_ARGS__); \
        }
#define NN_ASSERT_SDK_MIN(var, min)                                                                                                                \
        if ((var) < (min)) {                                                                                                                       \
                nndbgBreakWithTMessage_(NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s(=%d) must be >= %s(=%d).", #var, var, #min, min); \
        }
#define NN_ASSERT_SDK_MAX(var, max)                                                                                                                \
        if ((var) > (max)) {                                                                                                                       \
                nndbgBreakWithTMessage_(NN_DBG_BREAK_REASON_ASSERT, __BASE_FILE__, __LINE__, "%s(=%d) must be <= %s(=%d).", #var, var, #max, max); \
        }

#define NN_ASSERT_SDK_RESULT(cond, result)                                                                                          \
        if (!(cond)) {                                                                                                              \
                nndbgBreakWithResultMessage_(NN_DBG_BREAK_REASON_ASSERT, (nnResult)(result), __BASE_FILE__, __LINE__, "%s", #cond); \
        }

//#define NN_ASSERT_IDK_THIS_FORGOT_TODO_PLS_YEA(result)                    \
//        Result nn_result_try_result = (result); \
//        if (nn_result_try_result.IsFailure())   \
//        nndbgBreakWithResultMessage_(NN_DBG_BREAK_REASON_PANIC, (nnResult)(nn_result_try_result), __BASE_FILE__, __LINE__, "\"%s\" is Failure." #result)

#define NN_PANIC_SDK(...)                                            \
        nn::dbg::Printf("Panic: %s:%d\n", __BASE__FILE__, __LINE__); \
        nn::dbg::Printf(__VA_ARGS__);                                \
        nn::dbg::Printf("\n")                                        \
                nn::dbg::Panic();

#else
#define NN_ASSERT_SDK(cond)
#define NN_ASSERT_SDK_MSG(cond, ...)
#define NN_ASSERT_SDK_MIN(var, min)
#define NN_ASSERT_SDK_MAX(var, max)
#define NN_ASSERT_SDK_RESULT(cond, result)
#define NN_PANIC_SDK(...) nndbgPanic();
#endif
