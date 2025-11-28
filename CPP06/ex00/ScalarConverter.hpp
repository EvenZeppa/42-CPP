#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits.h>
#include <stdexcept>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(const std::string& literal);
};

#endif