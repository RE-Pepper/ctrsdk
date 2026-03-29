#pragma once

#include <nn/os/os_MemoryTypes.h>

namespace nn {
namespace os {

enum HandleInfoType
{
        HANDLE_INFO_TYPE_CREATION_TIME     = 0,
        HANDLE_INFO_TYPE_REFERENCE_COUNT   = 1,
        HANDLE_INFO_TYPE_PARENT_PROCESS_ID = 2,
        HANDLE_INFO_TYPE_MAX_BIT           = 2147483648,
};

enum ProcessInfoType
{
        PROCESS_INFO_TYPE_USING_PHYSICAL_MEMORY_SIZE       = 0,
        PROCESS_INFO_TYPE_MAX_USING_PHYSICAL_MEMORY_SIZE   = 1,
        PROCESS_INFO_TYPE_PRIVATE_PHYSICAL_MEMORY_SIZE     = 2,
        PROCESS_INFO_TYPE_MAX_RPIVATE_PHYSICAL_MEMORY_SIZE = 3,
        PROCESS_INFO_TYPE_NUM_HANDLES                      = 4,
        PROCESS_INFO_TYPE_MAX_NUM_HANDLES                  = 5,
        PROCESS_INFO_TYPE_NUM_CREATED_THREADS              = 6,
        PROCESS_INFO_TYPE_NUM_THREADS                      = 7,
        PROCESS_INFO_TYPE_MAX_NUM_THREADS                  = 8,
        PROCESS_INFO_TYPE_CPU_TIME_SYSTEM                  = 9,
        PROCESS_INFO_TYPE_CPU_TIME_USER                    = 10,
        PROCESS_INFO_TYPE_CPU_TIME                         = 11,
        PROCESS_INFO_TYPE_NUM_THREAD_SWITCH                = 12,
        PROCESS_INFO_TYPE_NUM_FPU_SWITCH                   = 13,
        PROCESS_INFO_TYPE_NUM_PROCESS_SWITCH               = 14,
        PROCESS_INFO_TYPE_NUM_SYSTEM_CALL                  = 15,
        PROCESS_INFO_TYPE_NUM_IPC                          = 16,
        PROCESS_INFO_TYPE_UPTIME                           = 17,
        PROCESS_INFO_TYPE_NAME                             = 18,
        PROCESS_INFO_TYPE_REGION                           = 19,
        PROCESS_INFO_TYPE_DEVICE_ADDRESS_OFFSET            = 20,
        PROCESS_INFO_TYPE_WRAM_ADDRESS_OFFSET              = 21,
        PROCESS_INFO_TYPE_WRAM_ADDRESS                     = 22,
        PROCESS_INFO_TYPE_WRAM_SIZE                        = 23,
        PROCESS_INFO_TYPE_MAX_BIT                          = 2147483648,
};

enum LimitableResource
{
        LIMITABLE_RESOURCE_MAX_PRIORITY       = 0,
        LIMITABLE_RESOURCE_MAX_COMMIT         = 1,
        LIMITABLE_RESOURCE_MAX_THREAD         = 2,
        LIMITABLE_RESOURCE_MAX_EVENT          = 3,
        LIMITABLE_RESOURCE_MAX_MUTEX          = 4,
        LIMITABLE_RESOURCE_MAX_SEMAPHORE      = 5,
        LIMITABLE_RESOURCE_MAX_TIMER          = 6,
        LIMITABLE_RESOURCE_MAX_SHAREDMEMORY   = 7,
        LIMITABLE_RESOURCE_MAX_ADDRESSARBITER = 8,
        LIMITABLE_RESOURCE_MAX_CPUTIME        = 9,
        LIMITABLE_RESOURCE_END                = 10,
        LIMITABLE_RESOURCE_MAX_BIT            = 2147483648,
};

enum ResetType
{
        RESET_TYPE_ONESHOT = 0, ///< When the primitive is signaled, it will wake up exactly one thread and will clear itself automatically.
        RESET_TYPE_STICKY  = 1, ///< When the primitive is signaled, it will wake up all threads and it won't clear itself automatically.
        RESET_TYPE_PULSE   = 2, ///< Only meaningful for timers: same as ONESHOT but it will periodically signal the timer instead of just once.
        RESET_TYPE_MAX_BIT = 2147483648,
};

enum ArbitrationType
{
        ARBITRATION_TYPE_SIGNAL                                       = 0, ///< Signal #value threads for wake-up.
        ARBITRATION_TYPE_WAIT_IF_LESS_THAN                            = 1, ///< If the memory at the address is strictly lower than #value, then wait for signal.
        ARBITRATION_TYPE_DECREMENT_AND_WAIT_IF_LESS_THAN              = 2, ///< If the memory at the address is strictly lower than #value, then decrement it and wait for signal.
        ARBITRATION_TYPE_WAIT_IF_LESS_THAN_WITH_TIMEOUT               = 3, ///< If the memory at the address is strictly lower than #value, then wait for signal or timeout.
        ARBITRATION_TYPE_DECREMENT_AND_WAIT_IF_LESS_THAN_WITH_TIMEOUT = 4, ///< If the memory at the address is strictly lower than #value, then decrement it and wait for signal or timeout.
        ARBITRATION_TYPE_MAX_BIT                                      = 2147483648,
};

} // namespace os
} // namespace nn
