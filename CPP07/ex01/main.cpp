#include "iter.hpp"

int main() {
    int array[] = {0, 1, 2, 3};
    iter(array, 4, printElement<int>);
    std::cout << std::endl;

    const int array1[] = {0, 1, 2, 3, 4, 5};
    iter(array1, 6, printElement<int>);
    std::cout << std::endl;

    std::string array2[] = {"Une", "phrase", "random"};
    iter(array2, 3, printElement<std::string>);
    std::cout << std::endl;
    
    return (0);
}