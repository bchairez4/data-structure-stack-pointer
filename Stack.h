/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Manual implementation of std::Stack using dynamic arrays pointers *
*    Progess: Basic implementation and functions are complete                *
*****************************************************************************/

#ifndef STACK_H
#define STACK_H

// LIFO
template <class T>
class Stack {
    private:
        int size_;
        int capacity_;
        T* array_;

        void resize_();
    public:
        Stack();
        Stack(const int& capacity);
        Stack(Stack<T>& other);
        ~Stack();
        T& operator=(const Stack<T>& other);
        void push(const T& data);
        void pop();
        T& top() const;
        bool contains(const T& data) const;
        bool empty() const;
        int capacity() const;
        int size() const;
};

#endif