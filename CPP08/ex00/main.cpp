#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 42);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}