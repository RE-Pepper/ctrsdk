#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fs/fs_Parameters.h>
#include <nn/fslow/fslow_Path.h>

namespace nn {
namespace fs {
namespace CTR {
namespace MPCore {

typedef nn::fslow::LowPath<const char*, const wchar_t*> Path;

class IFile
{
        virtual Result TryRead (s32*, s64, size_t)         = 0;
        virtual Result TryWrite (s32*, s64, size_t, bool)  = 0;
        virtual Result TryGetSize (s64*)                   = 0;
        virtual Result TrySetSize (s64)                    = 0;
        virtual Result TryFlush ()                         = 0;
        virtual Result DuplicateHandle (Handle*, s64, s64) = 0;
        virtual Handle GetFileHandle () const {}
        virtual void   DetachFileHandle () {}
        virtual void   Close () = 0;
        virtual ~IFile () {}
};
static_assert_ (sizeof (IFile) == 0x4);

class IDirectory
{
        virtual Result TryRead (s32*, DirectoryEntry, s32) = 0;
        virtual void   Close ()                            = 0;
        virtual ~IDirectory () {}
};
static_assert_ (sizeof (IDirectory) == 0x4);

class IArchive
{
        virtual Result OpenFile (IFile**, const Path&, bit32)      = 0;
        virtual Result OpenDirectory (IDirectory**, const Path&)   = 0;
        virtual Result DeleteFile (const Path&)                    = 0;
        virtual Result RenameFile (const Path&, const Path&)       = 0;
        virtual Result DeleteDirectory (const Path&)               = 0;
        virtual Result TryDeleteDirectoryRecursively (const Path&) = 0;
        virtual Result CreateFile (const Path&)                    = 0;
        virtual Result CreateDirectory (const Path&)               = 0;
        virtual Result RenameDirectory (const Path&, const Path&)  = 0;
        virtual Result GetFreeBytes (s64* pOut) {}
        virtual ~IArchive () {}
};
static_assert_ (sizeof (IArchive) == 0x4);

} // namespace MPCore
} // namespace CTR
} // namespace fs
} // namespace nn
