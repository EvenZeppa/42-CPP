#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main() {
    struct Data *data = new Data();

    data->id = 42;
    data->name = "name";

    std::cout << "Pointeur de data : " << data << std::endl;

    uintptr_t ptr;

    ptr = Serializer::serialize(data);

    std::cout << "Valeur de ptr : " << ptr << std::endl;

    data = Serializer::deserialize(ptr);

    std::cout << "Pointeur de data : " << data << std::endl;

    delete data;
    return (0);
}