#ifndef GU_CONTAINER_H_INCLUDED
#define GU_CONTAINER_H_INCLUDED
#include <cstddef>
#include <memory>
#include <cassert>

namespace GU
{
    namespace PS
    {

        template <class T>
        class Container final
        {
            public:
                Container(const std::size_t size);
                Container(const Container&)                 = delete;
                Container& operator = (const Container&)    = delete;
                T operator[](const std::size_t index);
                std::size_t Size() const;
                void recycle(const std::size_t index);
            private:
                std::unique_ptr<T[]> m_Container;
                const std::size_t m_Size = 0;
                std::size_t active = 0;
        };


        template <class T>
        Container<T>::Container(const std::size_t size):
        m_Container(new T[size]),
        m_Size(size)
        {
        }

        template <class T>
        std::size_t Container<T>::Size() const
        {
            return m_Size;
        }

        template <class T>
        void Container<T>::recycle(const std::size_t index)
        {
            assert(index < m_Size);
            assert(m_Container != nullptr);
            std::swap(m_Container + active, m_Container + index);
        }

        template <class T>
        T Container<T>::operator[](const std::size_t index)
        {
            assert(index < m_Size);
            assert(m_Container != nullptr);
            return m_Container[index];
        }
    }

}
#endif // CONTAINER_H_INCLUDED
