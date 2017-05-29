/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2015 - 2016  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace Fiene {

    template<class T>
    Stack<T>::Stack() :
            m_Head(nullptr), m_Counter(0)
    {

    }

    template<class T>
    Stack<T>::Stack(const Stack<T> &rhs) :
            m_Head(nullptr),
            m_Counter(rhs.m_Counter)
    {

        if (this != &rhs) {

            if (m_Head != nullptr) {
                Node *tmp;
                while (m_Head != nullptr) {
                    tmp = m_Head->next;
                    delete m_Head;
                    m_Head = tmp;
                    m_Counter--;
                }
            }

            m_Head = new Node(rhs.m_Head->Item);

            Node *iter = m_Head;
            for (Node *ptr = rhs.m_Head->next; ptr != nullptr; ptr = ptr->next) {
                iter->next = new Node(ptr->Item);
                iter = iter->next;
            }

            m_Counter = rhs.m_Counter;
        }

    }


    template<class T>
    Stack<T>& Stack<T>::operator =(const Stack<T> &rhs) {

        if (this != &rhs) {

            m_Head = nullptr;
            m_Counter = rhs.m_Counter;


            Node *tmp;
            while (m_Head != nullptr) {
                tmp = m_Head->next;
                delete m_Head;
                m_Head = tmp;
                m_Counter--;
            }

            m_Head = new Node(rhs.m_Head->Item);

            Node *iter = m_Head;
            for (Node *ptr = rhs.m_Head->next; ptr != nullptr; ptr = ptr->next) {
                iter->next = new Node(ptr->Item);
                iter = iter->next;
            }

            m_Counter = rhs.m_Counter;
        }

        return *this;
    }

    template<class T>
    Stack<T>::Stack(const Stack<T> &&rhs) :
            m_Head(rhs.m_Head),
            m_Counter(rhs.m_Counter)
    {

    }



    template<class T>
    Stack<T>&  Stack<T>::operator=(const Stack<T> &&rhs)
    {
        m_Head = rhs.m_Head;
        m_Counter = rhs.m_Counter;

        return *this;
    }

    template<class T>
    Stack<T>::~Stack() {
        Node *tmp;

        while (m_Head != nullptr) {
            tmp = m_Head->next;
            delete m_Head;
            m_Head = tmp;
            m_Counter--;
        }

    }

    template<class T>
    bool Stack<T>::push(const T &data) {

        Node *tmp = new Node();

        if (tmp != nullptr) {

            tmp->Item = data;
            tmp->next = m_Head;
            m_Head = tmp;
            m_Counter++;
            return (true);
        }
        else {
            return (false);
        }
    }

    template<class T>
    T Stack<T>::pop() noexcept {

        T tempItem;
        Node *tmp = m_Head;
        m_Head = m_Head->next;
        m_Counter--;
        tempItem = tmp->Item;
        delete tmp;
        return tempItem;
    }

    template<class T>
    T Stack<T>::top() const noexcept {
        return m_Head->Item;
    }

    template<class T>
    T Stack<T>::back() noexcept {
        if (!IsEmpty()) {

            Node *tmp = m_Head;

            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }

            return tmp->Item;
        }
    }

    template<class T>
    bool Stack<T>::IsEmpty() const {
        return (m_Counter == 0);
    }

    template<class T>
    size_t Stack<T>::size() const {
        return m_Counter;
    }

    template<class T>
    bool Stack<T>::popAndDelete() noexcept
    {
        Node *tmp = m_Head;
        m_Head = m_Head->next;
        m_Counter--;

        if (tmp->Item != nullptr) {
            delete tmp;
            return true;
        }

        return false;
    }

}



