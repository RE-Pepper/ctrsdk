#pragma once

#include <nn/util/util_TypeTraits.h>

namespace nn {
namespace fnd {
namespace ARMv6 {

// Primary template for 32-bit and smaller (s32, s16, s8, bool)
template <typename T>
struct LoadStoreRegEx
{
        static T LoadRegEx (volatile T* ptr)
        {
                return (T)__ldrex (ptr);
        }
        static int StoreRegEx (T val, volatile T* ptr)
        {
                return __strex (val, ptr);
        }
};

// Explicit specialization for 64-bit (s64)
// This matches the DWARF entry showing 8-byte LoadRegEx
template <>
struct LoadStoreRegEx<s64>
{
        static s64 LoadRegEx (volatile s64* ptr)
        {
                return __ldrexd (ptr);
        }
        static int StoreRegEx (s64 val, volatile s64* ptr)
        {
                return __strexd (val, ptr);
        }
};

} // namespace ARMv6

class Interlocked
{
        template <typename T, size_t Size = sizeof (T)>
        struct AtomicStorageSelecter;

        // Specialization for 8-byte types (like s64)
        template <typename T>
        struct AtomicStorageSelecter<T, 8>
        {
                typedef s64 Type;
        };
        // Specialization for 4-byte types (like s32 or 4-byte structs like 'Flags')
        template <typename T>
        struct AtomicStorageSelecter<T, 4>
        {
                typedef s32 Type;
        };
        // Specialization for 2-byte types (like s16)
        template <typename T>
        struct AtomicStorageSelecter<T, 2>
        {
                typedef s16 Type;
        };
        // Specialization for 1-byte types (like s8 or bool)
        template <typename T>
        struct AtomicStorageSelecter<T, 1>
        {
                typedef s8 Type;
        };

public:
        template <typename T, typename UpdateFunc>
        static bool AtomicUpdate (
                volatile T* p,
                UpdateFunc& update,
                typename nn::util::enable_if<sizeof (T) <= 4>::type* = 0)
        {
                typedef typename AtomicStorageSelecter<T>::Type StorageType;
                typedef ARMv6::LoadStoreRegEx<StorageType>      LoadStoreType;

                union U {
                        StorageType raw;
                        T           v;
                } u;

                while (true) {
                        // 1. Exclusively load the current value
                        u.raw = LoadStoreType::LoadRegEx (reinterpret_cast<volatile StorageType*> (p));

                        // Return #1: Abort path
                        // Call the functor. If it returns false/0, we clear the monitor and bail.
                        if (!update (u.v)) {
                                __clrex ();
                                return false;
                        }

                        // Return #2: Success path
                        // StoreRegEx returns 0 on SUCCESS (the exclusive monitor wasn't tripped).
                        if (LoadStoreType::StoreRegEx (u.raw, reinterpret_cast<volatile StorageType*> (p)) == 0) {
                                return true;
                        }
                }
        }
};
} // namespace fnd
} // namespace nn

