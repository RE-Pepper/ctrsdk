#pragma once

#include <nn/fnd/ARMv6/fnd_Interlocked.h>

namespace nn {
namespace fnd {

template <typename T>
class InterlockedVariable
{
private:
        template <typename U, typename = void>
        struct StorageSelecter;

        template <typename U>
        struct StorageSelecter<U, typename nn::util::enable_if<sizeof (U) == sizeof (s64)>::type>
        {
                typedef s64 Type;
        };
        template <typename U>
        struct StorageSelecter<U, typename nn::util::enable_if<sizeof (U) == sizeof (s32)>::type>
        {
                typedef s32 Type;
        };
        template <typename U>
        struct StorageSelecter<U, typename nn::util::enable_if<sizeof (U) == sizeof (s16)>::type>
        {
                typedef s16 Type;
        };
        template <typename U>
        struct StorageSelecter<U, typename nn::util::enable_if<sizeof (U) == sizeof (s8)>::type>
        {
                typedef s8 Type;
        };

        // AssignFunc (size = 4)
        struct AssignFunc
        {
                s32 m_operand;

                template <typename U>
                AssignFunc (const U& operand)
                    : m_operand (operand)
                {}

                bool operator() (s32& other)
                {
                        return true;
                }
        };
        // CompareAndSwapFunc (size = 12)
        struct CompareAndSwapFunc
        {
                s32 m_comparand;
                s32 m_value;
                s32 m_result;

                CompareAndSwapFunc (s32 comparand, s32 value)
                    : m_comparand (comparand), m_value (value)
                {}

                bool operator() (s32& x)
                {
                        return false;
                }
        };

private:
        volatile T m_v;

public:
        InterlockedVariable ()
            : m_v ()
        {}

        operator T () const
        {
                return m_v;
        }

        template <typename U>
        void operator= (U value)
        {
                AssignFunc func (value);
                AtomicUpdateConditional (func);
        }

        template <typename UpdateFunc>
        bool AtomicUpdateConditional (UpdateFunc& func)
        {
                return ARMv6::Interlocked::AtomicUpdate (&m_v, func);
        }
};

} // namespace fnd
} // namespace nn
