#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

Base * generate(void) {
    int rand = std::rand() % 3;

    if (rand == 0) return (new A());
    if (rand == 1) return (new B());
    if (rand == 2) return (new C());
    return (NULL);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::exception e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception e) {}
}

int main() {
    std::srand(std::time(NULL));

    Base* p = generate();

    identify(p);
    identify(&(*p));

    return (0);
}