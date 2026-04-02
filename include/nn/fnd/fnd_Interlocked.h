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

        struct AssignFunc
        {
                T m_operand;

                template <typename U>
                AssignFunc (const U& operand)
                    : m_operand (operand)
                {}

                bool operator() (T& x)
                {
                        x = m_operand;
                        return true;
                }
        };
        struct PreIncFunc
        {
                bool operator() (T& x)
                {
                        ++x;
                        return true;
                }
        };
        struct PreDecFunc
        {
                bool operator() (T& x)
                {
                        --x;
                        return true;
                }
        };
        struct CompareAndSwapFunc
        {
                T m_comparand;
                T m_value;
                T m_result;

                CompareAndSwapFunc (T comparand, T value) : m_comparand (comparand), m_value (value) {}

                bool operator() (T& x)
                {
                        m_result = x;
                        if (x == m_comparand) {
                                x = m_value;
                                return true;
                        }
                        return false;
                }
        };

private:
        volatile T m_v;

public:
        InterlockedVariable () : m_v () {}

        operator T () const { return m_v; }

        template <typename U>
        void operator= (U value)
        {
                AssignFunc func (value);
                AtomicUpdateConditional (func);
        }

        void operator++ ()
        {
                PreIncFunc func;
                AtomicUpdateConditional (func);
        }
        void operator-- ()
        {
                PreDecFunc func;
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
