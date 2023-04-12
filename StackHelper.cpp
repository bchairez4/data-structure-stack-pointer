/*****************************************************************************
    Helper Functions: DRY(Don't Repeat Yourself) 
*****************************************************************************/
// Copies the contents from array2 to array1 given a size for range purposes
template <class T>
void deepcopy(T* &array1, T* &array2, int& size) {
    for (int i = 0; i < size; ++i) {
        array1[i] = array2[i];
    }
}

// Deletes array ptr and sets array ptr to null
template <class T>
void memoryManage(T* &array) {
    delete [] array;
    array = nullptr;
}

// Swaps pointers between two array ptrs
template <class T>
void swap(T* &array1, T* &array2) {
    T* temp_array_ptr = array1;

    array1 = array2;
    array2 = temp_array_ptr;

    temp_array_ptr = nullptr;
}

