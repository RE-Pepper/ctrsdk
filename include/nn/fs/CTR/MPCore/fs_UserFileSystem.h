#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fslow/fslow_Path.h>

namespace nn {
namespace fs {
namespace CTR {
namespace MPCore {

typedef nn::fslow::LowPath<const char*, const wchar_t*> Path; // 34

namespace detail {

class UserFileSystem
{
public:
        static Result Initialize (Handle handle);
        static void   Finalize ();
        static void** OpenDirect (Handle handle);
        static void   OpenDirect (void*);
        static Handle GetFileHandle (void*);
        static void   DetachHandle (void*);
        static Result DuplicateHandleForFile (Handle* pOut, void*, s64, s64);
        static Result TryOpenFile (void**, const wchar_t*, bit32);
        static void   CloseFile (void* p);
        static Result TryReadFile (s32*, void*, s64, void*, size_t);
        static Result TryWriteFile (s32*, void*, s64, const void*, size_t, bool);
        static Result TryGetFileSize (s64*, const void*);
        static Result TrySetFileSize (void*, s64);
        static Result TryFlush (void*);
        static Result TryOpenDirectory (void**, const wchar_t*);
        static void   CloseDirectory (void*);
        static Result TryReadDirectory (s32*, void*, class DirectoryEntry*, s32);
        static Result TryDeleteFile (const wchar_t*);
        static Result TryRenameFile (const wchar_t*, const wchar_t*);
        static Result TryDeleteDirectory (const wchar_t*);
        static Result TryDeleteDirectoryRecursively (const wchar_t*);
        static Result TryCreateFile (const wchar_t*, s64);
        static Result TryCreateDirectory (const wchar_t*);
        static Result TryRenameDirectory (const wchar_t*, const wchar_t*);
        static Result TryOpenFileRaw (void**, ArchiveHandle, const Path&, bit32);
        static Result TryOpenFileRawDirectly (void**, bit32, const Path&, const Path&, bit32);
        static Result TryOpenDirectoryRaw (void**, ArchiveHandle, const Path&);
        static Result TryDeleteFileRaw (ArchiveHandle, const Path&);
        static Result TryRenameFileRaw (ArchiveHandle, const Path&, ArchiveHandle, const Path&);
        static Result TryDeleteDirectoryRaw (ArchiveHandle, const Path&);
        static Result TryDeleteDirectoryRecursivelyRaw (ArchiveHandle, const Path&);
        static Result TryCreateDirectoryRaw (ArchiveHandle, const Path&);
        static Result TryRenameDirectoryRaw (ArchiveHandle, const Path&, ArchiveHandle, const Path&);
};

} // namespace detail
} // namespace MPCore
} // namespace CTR

namespace detail {

// TODO: This cant be right being here.
void ForceDisableLatencyEmulation ();

} // namespace detail

} // namespace fs
} // namespace nn
