#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
private:
    unsigned int _size;
    unsigned int _maxSize;
    std::vector<int> _v;
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int nb);
    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        for (Iterator it = begin; it != end; ++it) {
            if (_size == _maxSize)
                throw std::out_of_range("Can't add numner : Span is full");
            _v.push_back(*it);
            _size++;
        }
    }
};

#endif