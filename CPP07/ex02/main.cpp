#include "Array.hpp"
#include <iostream>

template <typename T>
void printArray(const Array<T>& array) {
    std::cout << "Size = " << array.size() << std::endl;
    for (unsigned int i = 0; i < array.size(); i++)
        std::cout << i << ": " << array[i] << std::endl;
}

int main() {
    Array<int>array1;
    printArray(array1);
    std::cout << std::endl;

    Array<unsigned int>array2(4);
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    printArray(array2);
    try {
        array2[42] = 42;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    Array<unsigned int>array3(array2);
    array2[0] = 42;
    printArray(array3);
    std::cout << std::endl;

    array3 = array2;
    printArray(array3);
    std::cout << std::endl;

    const Array<unsigned int>array4(array2);
    // INTERDIT
    // array4[0] = 0
    printArray(array4);
    std::cout << std::endl;

    return (0);
}