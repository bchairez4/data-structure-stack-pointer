#include "Stack.h"
#include "StackHelper.cpp"

/*****************************************************************************
    Constructors/ Destructor
*****************************************************************************/
template <class T>
Stack<T>::Stack() : size_(0), capacity_(1), array_(nullptr) {
    array_ = new T[capacity_];
}

template <class T>
Stack<T>::Stack(const int& capacity) : size_(0), capacity_(capacity), array_(nullptr) {
    if (capacity_ <= 0) {
        capacity_ = 1;
    }

    array_ = new T[capacity_];
}

template <class T>
Stack<T>::Stack(Stack<T>& other) : size_(other.size_), capacity_(other.capacity_), array_(nullptr) {
    array_ = new T[capacity_];

    deepcopy(array_, other.array_, size_);
}


template <class T>
Stack<T>::~Stack() {
    memoryManage(array_);
    capacity_ = 1;
    size_ = 0;
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
template <class T>
T& Stack<T>::operator=(const Stack<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    array_ = new T[capacity_];

    deepcopy(array_, other.array_, size_);
}

/*****************************************************************************
    Data Modification/ Manipulation
*****************************************************************************/
template <class T>
void Stack<T>::push(const T& data) {
    if (size_ >= capacity_) {
        resize_();
    }

    array_[size_] = data;
    ++size_;
}

//Returns top most element. DO NOT USE WHEN STACK IS EMPTY
template <class T>
T& Stack<T>::top() const {
    return array_[size_ - 1];
}

//Destroys element at the top
template <class T>
void Stack<T>::pop() {
    //need to be able to handle when the stack is empty look into try catch and throw. Used them quite a bit with that one class
    T* temp_array = new T[capacity_];

    //Copying everything except what was on top of the stack 
    int updated_size = size_ - 1;
    deepcopy(temp_array, array_, updated_size);
    --size_;

    swap(temp_array, array_);
    memoryManage(temp_array);

}

/*****************************************************************************
    Data Observation
*****************************************************************************/
template <class T>
bool Stack<T>::contains(const T& data) const {
    for (int i = 0; i < size_; ++i) {
        if (data == array_[i]) {
            return true;
        }
    }

    return false;
}

template <class T>
bool Stack<T>::empty() const {
    return size_ == 0;
}

template <class T>
int Stack<T>::capacity() const {
    return capacity_;
}

template <class T>
int Stack<T>::size() const {
    return size_;
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
template <class T>
void Stack<T>::resize_() {
    capacity_ *= 2;

    T* temp_array = new T[capacity_];
    deepcopy(temp_array, array_, size_);
    
    swap(temp_array, array_);
    memoryManage(temp_array);
}