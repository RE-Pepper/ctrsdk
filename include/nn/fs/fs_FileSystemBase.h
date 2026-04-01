#pragma once

#include <nn/fs/CTR/MPCore/fs_UserFileSystem.h>

namespace nn {
namespace fs {
namespace detail {

class FileSystemBaseImpl : public CTR::MPCore::detail::UserFileSystem
{
};

class FileSystemBase
{
private:
        FileSystemBaseImpl m_pImpl;

public:
        FileSystemBase ();

        void   Initialize (FileSystemBaseImpl*);
        Result TryDeleteFile (const char*);
        Result TryRenameFile (const char*, const char*);
        Result TryCreateFile (const char*, s64);
        Result TryCreateDirectory (const char*);
};

class WPathBuffer
{
private:
        wchar_t m_pBuffer[270];

public:
        WPathBuffer (const char*);
};

} // namespace detail
} // namespace fs
} // namespace nn
