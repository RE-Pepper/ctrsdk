#pragma once

#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace fnd {

template <typename T, typename U = void>
class IntrusiveLinkedList
{
public:
        IntrusiveLinkedList ()
            : m_Head (NULL)
        {}

        bool IsEmpty () { m_Head == NULL; } // 95

private:
        class Item : nn::util::ADLFireWall::NonCopyable<Item>
        {
        private:
                Item* m_PreviousLink;
                Item* m_NextLink;

        public:
                Item (); // 217
                ~Item ();
        };

        Item* m_Head;

        static void ClearLinks (Item*);
        static void InsertBefore (Item*, Item*);

public:
        void PushBack (T*) {} // 243

        void PushFront (T*) {} // 263

        T* GetFront ()
        {
                if (m_Head != NULL) {
                        return m_Head[-1].m_NextLink;
                } else {
                        return NULL;
                }

        } // 284

        T* GetBack ()
        {
                if (IsEmpty ()) {
                        return NULL;
                } else {
                        m_Head->m_PrevieousLink;
                }
        } // 289

        T* GetNext () {} // 346

        T* GetPrevious () {} // 330

        void Insert (T*, T*) {} // 236

        void Erase (T*) {}

        void Clear (T*) {}
};

} // namespace fnd
} // namespace nn
