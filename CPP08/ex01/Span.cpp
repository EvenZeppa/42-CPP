#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() :  _size(0), _maxSize(0) {}

Span::Span(unsigned int n) : _size(0), _maxSize(n) {}

Span::Span(const Span& other) : _size(other._size), _maxSize(other._maxSize) {
    std::vector<int>::const_iterator it;

    for (it = other._v.begin(); it != other._v.end(); ++it) {
        _v.push_back(*it);
    }
}

Span& Span::operator=(const Span& other) {
    _v.clear();

    _maxSize = other._maxSize;
    _size = other._size;

    std::vector<int>::const_iterator it;

    for (it = other._v.begin(); it != other._v.end(); ++it) {
        _v.push_back(*it);
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
    if (_size == _maxSize)
        throw std::out_of_range("Can't add numner : Span is full");
    _v.push_back(nb);
    _size++;
}

int Span::shortestSpan() {
    if (_size < 2)
        throw std::logic_error("Not enough values to find shortest span");
    std::vector<int> v = _v;

    std::sort(v.begin(), v.end());
    int ss = v[1] - v[0];
    for (unsigned int i = 1; i < _size; i++) {
        if (v[i] - v[i - 1] < ss)
            ss = v[i] - v[i - 1];
    }
    return (ss);
}

int Span::longestSpan() {
    if (_size < 2)
        throw std::logic_error("Not enough values to find shortest span");
    int min = *std::min_element(_v.begin(), _v.end());
    int max = *std::max_element(_v.begin(), _v.end());
    return max - min;
}