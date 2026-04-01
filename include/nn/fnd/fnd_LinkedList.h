#pragma once

#include <nn/assert.h>
#include <nn/fnd/fnd_Result.h>
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

        class Item;

private:
        bool  IsEmpty () { m_Head == NULL; } // 95
        Item* m_Head;

        static void ClearLinks (Item* p)
        {
                p->m_NextLink     = NULL;
                p->m_PreviousLink = NULL;
        }
        static void InsertBefore (Item* p, Item* q)
        {
                q->m_NextLink                 = p;
                p->m_PreviousLink->m_NextLink = q;
                q->m_PreviousLink             = q->m_PreviousLink;
                p->m_PreviousLink             = q;
        }

public:
        class Item : nn::util::ADLFireWall::NonCopyable<Item>
        {
        private:
                Item* m_PreviousLink;
                Item* m_NextLink;

        public:
                Item ()
                    : m_PreviousLink (NULL),
                      m_NextLink (NULL)
                {} // 217
                ~Item ()
                {
                        NN_ASSERT_SDK (!m_PreviousLink && !m_NextLink) // 218
                }
        };

        void PushBack (T* p)
        {
                NN_ASSERT_SDK_RESULT (p, ResultInvalidAddress ()); // 244
                NN_ASSERT_SDK (p);                                 // 245
                Item* pNode = (Item*)p;
                NN_ASSERT_SDK_RESULT (!pNode->m_PreviousLink, ResultFndUnk0 ()); // 247
                NN_ASSERT_SDK (!pNode->m_PreviousLink);                          // 248
                NN_ASSERT_SDK (!pNode->m_NextLink);                              // 249

                if (IsEmpty ()) {
                        p->m_PreviousLink = p;
                        p->m_NextLink     = p;
                        this->m_Head      = p;
                } else {
                        InsertBefore (this->m_Head);
                }
        } // 243

        void PushFront (T* p)
        {
                NN_ASSERT_SDK_RESULT (p, ResultInvalidAddress ());
                NN_ASSERT_SDK (p);
                Item* pNode = (Item*)p;
                NN_ASSERT_SDK_RESULT (!pNode->m_PreviousLink, ResultFndUnk0 ());
                NN_ASSERT_SDK (!pNode->m_PreviousLink);
                NN_ASSERT_SDK (!pNode->m_NextLink);

                if (IsEmpty ()) {
                        p->m_PreviousLink = p;
                        p->m_NextLink     = p;
                } else {
                        InsertBefore (this->m_Head);
                }
                this->m_Head = p;
        } // 263

        T* GetFront ()
        {
                if (m_Head == NULL) {
                        return NULL;
                }

                return m_Head[-1].m_NextLink;

        } // 284

        T* GetBack ()
        {
                if (IsEmpty ()) {
                        return NULL;
                }

                return m_Head->m_PrevieousLink;
        } // 289

        T* GetNext (T* p)
        {
                NN_ASSERT_SDK_RESULT (p, ResultInvalidAddress ());
                NN_ASSERT_SDK (p);
                Item* pNode = (Item*)p;
                NN_ASSERT_SDK_RESULT (!pNode->m_PreviousLink, ResultFndUnk0 ());
                NN_ASSERT_SDK (!pNode->m_PreviousLink);
                NN_ASSERT_SDK (!pNode->m_NextLink);

                if (GetBack () == p) {
                        return NULL;
                } else {
                        return p->m_NextLink;
                }
        } // 346

        T* GetPrevious (T* p)
        {
                NN_ASSERT_SDK_RESULT (p, ResultInvalidAddress ());
                NN_ASSERT_SDK (p);
                Item* pNode = (Item*)p;
                NN_ASSERT_SDK_RESULT (!pNode->m_PreviousLink, ResultFndUnk0 ());
                NN_ASSERT_SDK (!pNode->m_PreviousLink);
                NN_ASSERT_SDK (!pNode->m_NextLink);

                if (GetFront () == p) {
                        return NULL;
                } else {
                        return p->m_PreviousLink;
                }
        } // 330

        void Insert (T* p, T* q)
        {
                q->m_NextLink                 = p;
                p->m_PreviousLink->m_NextLink = q;
                q->m_PreviousLink             = p->m_PreviousLink;
                p->m_PreviousLink             = q;
        } // 236

        void Erase (T* p)
        {
                NN_ASSERT_SDK_RESULT (p, ResultInvalidAddress ());
                NN_ASSERT_SDK (p);
                Item* pNode = (Item*)p;
                NN_ASSERT_SDK_RESULT (!pNode->m_PreviousLink, ResultFndUnk0 ());
                NN_ASSERT_SDK (!pNode->m_PreviousLink);
                NN_ASSERT_SDK (!pNode->m_NextLink);

                if (p->m_PreviousLink == p) {
                        this->m_Head = NULL;
                } else {
                        if (this->m_Head == p) {
                                this->m_Head = this->m_Head->m_NextLink;
                        }
                        p->m_NextLink->m_PreviousLink = p->m_PreviousLink;
                        p->m_PreviousLink->m_NextLink = p->m_NextLink;
                }
                ClearLinks (p);
        }

        void Clear (T*)
        {
                if (this->m_Head) {
                        Item* p = this->m_Head;
                        while (p) {
                                Item* q = p;
                                p       = p->m_NextLink;
                                ClearLinks (q);
                        }
                        this->m_Head = NULL;
                }
        }
};

} // namespace fnd
} // namespace nn
