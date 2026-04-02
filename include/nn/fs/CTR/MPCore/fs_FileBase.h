#pragma once

#include <nn/Result.h>
#include <nn/assert.h>
#include <nn/fs/CTR/MPCore/fs_UserFileSystem.h>
#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace fs {
namespace detail {

class FileBaseImpl : nn::util::ADLFireWall::NonCopyable<FileBaseImpl>
{
private:
        void* GetPtr ()
        {
                return (void*)((int)this->m_P & 0xFFFFFFFE);
        }
        void OpenDirect ()
        {
                // TODO
        }
        void NeedFlush ()
        {
                this->m_P = (void*)((int)this->m_P | 1);
        }
        void DoneFlush ()
        {
                this->m_P = (void*)((int)this->m_P & ~1);
        }
        bool IsNotFlushed ()
        {
                return (bool)((int)this->m_P & 1);
        }

        void* m_P;

public:
        FileBaseImpl () : m_P (NULL) {}
        Result TryOpenImpl (const wchar_t* path, bit32 mode)
        {
                return CTR::MPCore::detail::UserFileSystem::TryOpenFile (&this->m_P, path, mode);
        }
        Result TryRead (s32* pOut, s64 offset, void* buffer, size_t size)
        {
                return CTR::MPCore::detail::UserFileSystem::TryReadFile (pOut, GetPtr (), offset, buffer, size);
        }
        Result TryWrite (s32* pOut, s64 offset, const void* buffer, size_t size, bool flush)
        {
                if (flush) {
                        DoneFlush ();
                } else {
                        NeedFlush ();
                }

                return CTR::MPCore::detail::UserFileSystem::TryWriteFile (pOut, GetPtr (), offset, buffer, size, flush);
        }
        Result TryGetSize (s64* pOut)
        {
                return CTR::MPCore::detail::UserFileSystem::TryGetFileSize (pOut, GetPtr ());
        }
        Result TrySetSize (s64 size)
        {
                return CTR::MPCore::detail::UserFileSystem::TrySetFileSize (GetPtr (), size);
        }
        Result TryFlush ()
        {
                return CTR::MPCore::detail::UserFileSystem::TryFlush (GetPtr ());
        }

        void Finalize ()
        {
                if (GetPtr () != NULL) {
                        NN_ASSERT_SDK (!IsNotFlushed ());
                        CTR::MPCore::detail::UserFileSystem::CloseFile (GetPtr ());
                        this->m_P = NULL;
                }
        }

        ~FileBaseImpl ()
        {
                Finalize ();
        }
};
static_assert_ (sizeof (FileBaseImpl) == 0x4);

} // namespace detail
} // namespace fs
} // namespace nn
