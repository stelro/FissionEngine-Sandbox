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

#ifndef PROJECT_STACK_HPP
#define PROJECT_STACK_HPP

//C++ Includes
#include <cstddef>

namespace Fiene {

    template<typename T>
    class Stack {
    private:

        //Node neasted class
        class Node {
        public:
            T Item;
            Node *next;

            Node() : next(nullptr) { }

            Node(T value) : Item(value), next(nullptr) { }
        };

        Node*               m_Head;
        size_t              m_Counter; // stack nodes counter

    public:
        Stack();
        Stack(const Stack<T>& rhs); // copy constructor
        Stack<T>& operator =(const Stack<T>& rhs); // copy assigment operator
        Stack(const Stack<T>&& rhs); // copy move constructor
        Stack<T>&operator =(const Stack<T>&& rhs); //copy move assigment operator
        ~Stack();

        bool push(const T &data);

        T pop() noexcept;

        bool popAndDelete() noexcept ;

        bool IsEmpty() const;

        T top() const noexcept;

        T back() noexcept;

        size_t size() const;
    };

}

#include "Stack.inl"


#endif //PROJECT_STACK_HPP
