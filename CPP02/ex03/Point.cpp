#include "Point.hpp"


Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const &point) : x(point.x), y(point.y) {}

Point::~Point() {}

Fixed const Point::getX() const { return x; }

Fixed const Point::getY() const { return y; }

std::ostream& operator<<(std::ostream &os, Point const &point)
{
	os << "(" << point.getX() << "," << point.getY() << ")" << std::endl;
	return (os);
}
