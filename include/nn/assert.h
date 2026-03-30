#pragma once

#include <nn/Handle.h>
#include <nn/dbg/dbg_Break.h>

#ifndef NN_SWITCH_DISABLE_ASSERT_WARNING_FOR_SDK
#define NN_ASSERT_SDK(cond)                                                                            \
        if (!(cond)) {                                                                                 \
                nndbgBreakWithTMessage_ (NN_DBG_BREAK_REASON_ASSERT, __FILE__, __LINE__, "%s", #cond); \
        }

#define NN_ASSERT_SDK_RESULT(res) \
        NN_ASSERT_SDK (res.IsSuccess ())
#else
#define NN_ASSERT_SDK(cond)
#define NN_ASSERT_SDK_RESULT(res)
#endif

#ifndef NN_SWITCH_DISABLE_DEBUG_PRINT_FOR_SDK
#else
#endif
