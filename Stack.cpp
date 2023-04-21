#include "Stack.h"
#include "StackHelper.cpp"

/*****************************************************************************
    Constructors/ Destructor
*****************************************************************************/
// Time Complexity: O(N), where N in this case is equal to 1.
template <class T>
Stack<T>::Stack() : size_(0), capacity_(1), array_(nullptr) {
    array_ = new T[capacity_];
}

// Time Complexity: O(N), where N is the number specified by capacity.
template <class T>
Stack<T>::Stack(const int& capacity) : size_(0), capacity_(capacity), array_(nullptr) {
    if (capacity_ <= 0) {
        capacity_ = 1;
    }

    array_ = new T[capacity_];
}

// Time Complexity: O(N), where N is the number of elements in other.
template <class T>
Stack<T>::Stack(Stack<T>& other) : size_(other.size_), capacity_(other.capacity_), array_(nullptr) {
    array_ = new T[capacity_];

    deepcopy(array_, other.array_, size_);
}


// Time Complexity: O(1)
template <class T>
Stack<T>::~Stack() {
    memoryManage(array_);
    capacity_ = 1;
    size_ = 0;
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
// Time Complexity: O(N), where N is the number of elements in other.
template <class T>
T& Stack<T>::operator=(const Stack<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    array_ = new T[capacity_];

    deepcopy(array_, other.array_, size_);
}

/*****************************************************************************
    Data Modification
*****************************************************************************/
// Time Complexity: O(1) amortized. O(N) until the stack is big enough to not need a resize as often.
template <class T>
void Stack<T>::push(const T& data) {
    if (size_ >= capacity_) {
        resize_();
    }

    array_[size_] = data;
    ++size_;
}

//Returns top most element. DO NOT USE WHEN STACK IS EMPTY
// Time Complexity: O(1)
template <class T>
T& Stack<T>::top() const {
    return array_[size_ - 1];
}

//Destroys element at the top
// Time Complexity: O(N), where N is the number of elements in the stack.
template <class T>
void Stack<T>::pop() {
    if (empty()) {
        return;
    }
    
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
// Time Complexity: O(N), where N is the number of elements in the stack.
template <class T>
bool Stack<T>::contains(const T& data) const {
    for (int i = 0; i < size_; ++i) {
        if (data == array_[i]) {
            return true;
        }
    }

    return false;
}

// Time Complexity: O(1)
template <class T>
bool Stack<T>::empty() const {
    return size_ == 0;
}

// Time Complexity: O(1)
template <class T>
int Stack<T>::capacity() const {
    return capacity_;
}

// Time Complexity: O(1)
template <class T>
int Stack<T>::size() const {
    return size_;
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
// Time Complexity: O(N), where N is the number of elements in the stack.
template <class T>
void Stack<T>::resize_() {
    capacity_ *= 2;

    T* temp_array = new T[capacity_];
    deepcopy(temp_array, array_, size_);
    
    swap(temp_array, array_);
    memoryManage(temp_array);
}