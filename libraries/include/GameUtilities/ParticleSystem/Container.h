#ifndef GU_CONTAINER_H_INCLUDED
#define GU_CONTAINER_H_INCLUDED
#include <cstddef>
#include <memory>
#include <cassert>
/************************************************************//**
*   @file   Container.h
*   @date   4/14/2018
*   @author Wayne J Larson Jr.
****************************************************************/
namespace GU
{
    namespace PS
    {
        //forward declaration for iterator
        template <class T>
        class ContainerIterator;


        //forward declaration for reverse iterator
        template <class T>
        class ContainerReverseIterator;


        /****************************************************//**
        *   @class  Container
        *   @brief  This container class is designed to recycle
        *           the objects it contains.
        ********************************************************/
        template <class T>
        class Container final
        {
            public:

                using iterator                  = ContainerIterator<T>;                ///iterator
                using reverse_iterator          = ContainerReverseIterator<T>;         ///reverse iterator
                using const_iterator            = const ContainerIterator<T>;          ///const iterator
                using const_reverse_iterator    = const ContainerReverseIterator<T>;   ///const revers iterator

                /****************************************************//**
                *   @brief  Constructor
                *   @param  capacity size the number of objects the container
                *           should hold.
                ********************************************************/
                Container(const std::size_t capacity);


                /****************************************************//**
                *   @brief  This container is not copy constructable
                ********************************************************/
                Container(const Container&)                 = delete;


                /****************************************************//**
                *   @brief  This container is not copy assignable
                ********************************************************/
                Container& operator = (const Container&)    = delete;


                /****************************************************//**
                *   @brief  Allows access to an element at the given
                *           index.
                *   @param  index the index of the element to be accessed
                *   @return a reference to the element at the given
                *           index.
                ********************************************************/
                T& operator[](const std::size_t index);


                /****************************************************//**
                *   @brief  Get the current size of the container.
                *           This is the number of currently active objects
                *   @return The number of currently active objects.
                ********************************************************/
                std::size_t size() const;


                /****************************************************//**
                *   @brief  Remove the object at index, and add
                *           it back to the pool of available objects.
                *   @param  index the index of the object to be recycled
                ********************************************************/
                void remove(const std::size_t index);


                /****************************************************//**
                *   @brief  Returns the total size of the container.
                *           This number represents all of the active
                *           and inactive objects.
                *   @return The total number of active and inactive objects
                *           in the container.
                ********************************************************/
                std::size_t capacity() const;


                /*************************************************************//**
                *   @brief  Construct an object of type T and place it in the
                *           back of the container.
                *   @tparam Args the arguments nesseccary to construct an
                *           object of type T.
                ****************************************************************/
                template <class... Args>
                void emplace_back(Args&&... args);


                /*************************************************************//**
                *   @brief  This method returns true when the container is empty.
                *   @return True when the container is empty.
                ****************************************************************/
                bool empty() const;


                /*************************************************************//**
                *   @brief  This method returns an iterator to the first element
                *           in the container.
                *   @return An iterator to the first element of the container.
                ****************************************************************/
                iterator begin();

                /*************************************************************//**
                *   @brief  This method returns an iterator to one past the
                *           last element of the container.
                *   @return An iterator to one past the last element of the
                *           container.
                ****************************************************************/
                iterator end();


                /*************************************************************//**
                *   @brief  This method returns a reverse_iterator to the last
                *           element of the container.
                *   @return A reverse_iterator to the last element of the
                *           container.
                ****************************************************************/
                reverse_iterator rbegin();


                /*************************************************************//**
                *   @brief  This method returns a reverse_iterator to one before
                *           the first element in the container.
                *   @return A reverse_iterator to one past the first element in
                *           the container.
                ****************************************************************/
                reverse_iterator rend();


                /*************************************************************//**
                *   @brief  This method returns a const iterator to the first
                *           element of the container.
                *   @return A const_iterator to the first element in the
                *           container.
                ****************************************************************/
                const_iterator cbegin()
                {
                    T *temp = &(*this)[0];
                    return Container<T>::const_iterator(temp);
                }


                /*************************************************************//**
                *   @brief  This method returns a const iterator to one past
                *           the last element in the container.
                *   @return A const_iterator to one past the last element in the
                *           container.
                ****************************************************************/
                const_iterator cend()
                {
                    T *temp = &(*this)[this->size()];
                    return Container<T>::const_iterator(temp);
                }


                /*************************************************************//**
                *   @brief  This method returns a const_reverse_iterator
                *           to the last element in the container.
                *   @return A const_reverse_iterator to the last element
                *           in the container
                ****************************************************************/
                const_reverse_iterator crbegin()
                {
                    T *temp = &(*this)[this->size()];
                    return Container<T>::const_reverse_iterator(temp);
                }


                /*************************************************************//**
                *   @brief  This method returns a const_reverse_iterator
                *           to one past the first element in the container
                *   @return A const_reverse_iterator to one past the first
                *           element in the container
                ****************************************************************/
                const_reverse_iterator crend()
                {
                    T *temp = &(*this)[0];
                    return Container<T>::const_reverse_iterator(temp);
                }
            private:
                std::unique_ptr<T[]> m_Container;
                std::size_t m_Size;
                std::size_t m_Capacity;
        };


        /****************************************************//**
        *   brief  Constructor
        *   param  capacity size the number of objects the container
        *           should hold.
        ********************************************************/
        template <class T>
        Container<T>::Container(const std::size_t capacity):
        m_Container(new T[capacity]),
        m_Size(0),
        m_Capacity(capacity)
        {
        }


        /****************************************************//**
        *   @brief  Get the current size of the container.
        *           This is the number of currently active objects
        *   @return The number of currently active objects.
        ********************************************************/
        template <class T>
        std::size_t Container<T>::size() const
        {
            return m_Size;
        }


        /****************************************************//**
        *   @brief  Remove the object at index, and add
        *           it back to the pool of available objects.
        *   @param  index the index of the object to be recycled
        ********************************************************/
        template <class T>
        void Container<T>::remove(const std::size_t index)
        {
            assert(index < m_Size);
            assert(m_Container != nullptr);
            std::swap(*(m_Container.get() + m_Size - 1),
                      *(m_Container.get() + index));
            --m_Size;
        }


        /****************************************************//**
        *   @brief  Allows access to an element at the given
        *           index.
        *   @param  index the index of the element to be accessed
        *   @return a reference to the element at the given
        *           index.
        ********************************************************/
        template <class T>
        T& Container<T>::operator[](const std::size_t index)
        {
            assert(index < m_Size);
            assert(m_Container != nullptr);
            return m_Container[index];
        }


        /****************************************************//**
        *   @brief  Returns the total size of the container.
        *           This number represents all of the active
        *           and inactive objects.
        *   @return The total number of active and inactive objects
        *           in the container.
        ********************************************************/
        template <class T>
        std::size_t Container<T>::capacity() const
        {
            return m_Capacity;
        }


        /*************************************************************//**
        *   @brief  This method returns true when the container is empty.
        *   @return True when the container is empty.
        ****************************************************************/
        template <class T>
        bool Container<T>::empty() const
        {
            return !bool(size());
        }


        /*************************************************************//**
        *   @brief  This method returns an iterator to the first element
        *           in the container.
        *   @return An iterator to the first element of the container.
        ****************************************************************/
        template <class T>
        typename Container<T>::iterator Container<T>::begin()
        {
            T *temp = &(*this)[0];
            return Container<T>::iterator(temp);
        }


        /*************************************************************//**
        *   @brief  This method returns an iterator to one past the
        *           last element of the container.
        *   @return An iterator to one past the last element of the
        *           container.
        ****************************************************************/
        template <class T>
        typename Container<T>::iterator Container<T>::end()
        {
            T *temp = &(*this)[this->size()];
            return Container<T>::iterator(temp);
        }


        /*************************************************************//**
        *   @brief  This method returns a reverse_iterator to the last
        *           element of the container.
        *   @return A reverse_iterator to the last element of the
        *           container.
        ****************************************************************/
        template <class T>
        typename Container<T>::reverse_iterator Container<T>::rbegin()
        {
            T *temp = &(*this)[this->size()];
            return Container<T>::reverse_iterator(temp);
        }


        /*************************************************************//**
        *   @brief  This method returns a reverse_iterator to one before
        *           the first element in the container.
        *   @return A reverse_iterator to one past the first element in
        *           the container.
        ****************************************************************/
        template <class T>
        typename Container<T>::reverse_iterator Container<T>::rend()
        {
            T *temp = &(*this)[0];
            return Container<T>::reverse_iterator(temp);
        }


        /*************************************************************//**
        *   @brief  This method returns a const iterator to the first
        *           element of the container.
        *   @return A const_iterator to the first element in the
        *           container.
        ****************************************************************/
        //template <class T>
        //typename Container<T>::const_iterator Container<T>::cbegin()
        //{
        //    T *temp = &(*this)[0];
        //    return Container<T>::const_iterator(temp);
        //}


        /*************************************************************//**
        *   @brief  This method returns a const iterator to one past
        *           the last element in the container.
        *   @return A const_iterator to one past the last element in the
        *           container.
        ****************************************************************/
        //template <class T>
        //typename Container<T>::const_iterator Container<T>::cend()
        //{
        //    T *temp = &(*this)[this->size()];
        //    return Container<T>::const_iterator(temp);
        //}


        /*************************************************************//**
        *   @brief  This method returns a const_reverse_iterator
        *           to the last element in the container.
        *   @return A const_reverse_iterator to the last element
        *           in the container
        ****************************************************************/
        //template <class T>
        //typename Container<T>::const_reverse_iterator Container<T>::crbegin()
        //{
        //    T *temp = &(*this)[this->size()];
        //    return Container<T>::const_reverse_iterator(temp);
        //}


        /*************************************************************//**
        *   @brief  This method returns a const_reverse_iterator
        *           to one past the first element in the container
        *   @return A const_reverse_iterator to one past the first
        *           element in the container
        ****************************************************************/
        //template <class T>
        //typename Container<T>::const_reverse_iterator Container<T>::crend()
        //{
        //    T *temp = &(*this)[0];
        //    return Container<T>::const_reverse_iterator(temp);
        //}


        /*************************************************************//**
        *   @brief  Construct an object of type T and place it in the
        *           back of the container.
        *   @tparam Args the arguments nesseccary to construct an
        *           object of type T.
        ****************************************************************/
        template <class T>
        template <class... Args>
        void Container<T>::emplace_back(Args&&... args)
        {
            assert(m_Size != m_Capacity);
            m_Container[m_Size++] = T(std::forward<Args>(args)...);

        }


        /****************************************************//**
        *   @class  ContainerIterator
        *   @brief  This class is an iterator class for
        *           the Container class
        ********************************************************/
        template <class T>
        class ContainerIterator
        {
            public:
                /****************************************************//**
                *   @brief  The default constructor is deleted
                ********************************************************/
                ContainerIterator() = delete;


                /****************************************************//**
                *   @brief  The default constructor is deleted
                ********************************************************/
                ContainerIterator(T *element);


                /****************************************************//**
                *   @brief  Overloaded pre increment operator.
                *   @return ContainerIterator<T> which points to the
                *           next element in the container.
                ********************************************************/
                ContainerIterator<T> operator ++();


                /****************************************************//**
                *   @brief  Overloaded post increment operator.
                *   @return An iterator to the current element in the
                *           container.
                ********************************************************/
                ContainerIterator<T> operator ++(int);


                /****************************************************//**
                *   @brief  Overloaded pre decrement operator.
                *   @return An iterator to the current element in the
                *           container.
                ********************************************************/
                ContainerIterator<T> operator --();


                /****************************************************//**
                *   @brief  Overloaded post decrement operator.
                *   @return An iterator to the current element in the
                *           container.
                ********************************************************/
                ContainerIterator<T> operator --(int);


                /****************************************************//**
                *   @brief  Overloaded equality operator.
                *   @param  param a ContainerIterator object to be
                *           checked against for equality.
                *   @return true if the (*this) and param are equal
                *           and false otherwise.
                ********************************************************/
                bool operator ==(const ContainerIterator<T> &param) const;


                /****************************************************//**
                *   @brief  Overloaded post increment operator.
                *   @param  param this is a dummy parameter to differentiate
                *           between the pre and post operator.
                *   @return An iterator to the current element in the
                *           container.
                ********************************************************/
                bool operator !=(const ContainerIterator<T> &param) const;


                /****************************************************//**
                *   @brief  Overloaded dereference operator.
                *   @return A reference to the object the iterator
                *           currently points to.
                ********************************************************/
                T& operator*();
            private:
                T *m_Element = nullptr;
        };


        /****************************************************//**
        *   @brief  The default constructor is deleted
        ********************************************************/
        template <class T>
        ContainerIterator<T>::ContainerIterator(T *element):
        m_Element(element)
        {

        }


        /****************************************************//**
        *   @brief  Overloaded pre increment operator.
        *   @return ContainerIterator<T> which points to the
        *           next element in the container.
        ********************************************************/
        template <class T>
        ContainerIterator<T> ContainerIterator<T>::operator ++()
        {
            ++m_Element;
            return *this;
        }


        /****************************************************//**
        *   @brief  Overloaded post increment operator.
        *   @return An iterator to the current element in the
        *           container.
        ********************************************************/
        template <class T>
        ContainerIterator<T> ContainerIterator<T>::operator ++(int)
        {
            T *temp(m_Element);
           this->operator ++();
            return temp;
        }


        /****************************************************//**
        *   @brief  Overloaded pre decrement operator.
        *   @return An iterator to the current element in the
        *           container.
        ********************************************************/
        template <class T>
        ContainerIterator<T> ContainerIterator<T>::operator --()
        {
            --m_Element;
            return *this;
        }


        /****************************************************//**
        *   @brief  Overloaded post decrement operator.
        *   @return An iterator to the current element in the
        *           container.
        ********************************************************/
        template <class T>
        ContainerIterator<T> ContainerIterator<T>::operator --(int)
        {
            T *temp(m_Element);
            this->operator--();

            return temp;
        }


        /****************************************************//**
        *   @brief  Overloaded equality operator.
        *   @param  param a ContainerIterator object to be
        *           checked against for equality.
        *   @return true if the (*this) and param are equal
        *           and false otherwise.
        ********************************************************/
        template <class T>
        bool ContainerIterator<T>::operator ==(const ContainerIterator<T> &param) const
        {
            return m_Element == param.m_Element;
        }


        /****************************************************//**
        *   @brief  Overloaded post increment operator.
        *   @param  param this is a dummy parameter to differentiate
        *           between the pre and post operator.
        *   @return An iterator to the current element in the
        *           container.
        ********************************************************/
        template <class T>
        bool ContainerIterator<T>::operator !=(const ContainerIterator<T> &param) const
        {
            return m_Element != param.m_Element;
        }


        /****************************************************//**
        *   @brief  Overloaded dereference operator.
        *   @return A reference to the object the iterator
        *           currently points to.
        ********************************************************/
        template <class T>
        T& ContainerIterator<T>::operator*()
        {

        }


        /****************************************************//**
        *   @class  ContainerReverseIterator
        *   @brief  This class is a reverse iterator class for
        *           the Container class
        ********************************************************/
        template <class T>
        class ContainerReverseIterator
        {
            public:
                ContainerReverseIterator() = delete;
                ContainerReverseIterator(T *element);
                ContainerReverseIterator<T> operator ++();
                ContainerReverseIterator<T> operator ++(int);
                ContainerReverseIterator<T> operator --();
                ContainerReverseIterator<T> operator --(int);
            private:
                T *m_Element = nullptr;
        };


        template <class T>
        ContainerReverseIterator<T>::ContainerReverseIterator(T *element):
        m_Element(element)
        {

        }


        template <class T>
        ContainerReverseIterator<T> ContainerReverseIterator<T>::operator ++()
        {
            --m_Element;
            return *this;
        }


        template <class T>
        ContainerReverseIterator<T> ContainerReverseIterator<T>::operator ++(int)
        {
            T *temp(m_Element);
            this->operator++();

            return temp;
        }


        template <class T>
        ContainerReverseIterator<T> ContainerReverseIterator<T>::operator --()
        {
            ++m_Element;
            return *this;
        }


        template <class T>
        ContainerReverseIterator<T> ContainerReverseIterator<T>::operator --(int)
        {
            T *temp(m_Element);
            this->operator --();

            return temp;
        }

    }

}
#endif // CONTAINER_H_INCLUDED
