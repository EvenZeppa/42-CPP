#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits.h>
#include <stdexcept>

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};