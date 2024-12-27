#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(float const x, float const y);
	Point(Point const &point);
	Point& operator=(Point const &point) = delete;
	~Point();

	friend std::ostream& operator<<(std::ostream &os, Point const &point);

	Fixed const getX() const;
	Fixed const getY() const;
};

#endif