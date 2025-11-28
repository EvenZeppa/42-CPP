#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printElement(const T &e) {
    std::cout << e << std::endl;
};

template <typename T, typename F>
void iter(T *array, const size_t length, F function) {
    for (size_t i = 0; i < length; i++)
        function(array[i]);
};

#endif