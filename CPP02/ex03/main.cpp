#include "Point.hpp"
#include <iostream>
#include <optional>

// Point getTriangleBarycentre(Point const a, Point const b, Point const c)
// {
// 	Fixed x = (a.getX() + b.getX() + c.getX()) / 3;
// 	Fixed y = (a.getY() + b.getY() + c.getY()) / 3;

// 	Point barycentre(x.toFloat(), y.toFloat());

// 	return (barycentre);
// }

// std::optional<Point>	findIntersection(Point const a, Point const b, Point const c, Point const d)
// {
// 	Fixed	denominator((a.getX() - b.getX()) * (c.getY() - d.getY()) - (a.getY() - b.getY()) * (c.getX() - d.getX()));

// 	if (denominator == 0)
// 		return (std::nullopt);
	
// 	Fixed t = ((a.getX() - c.getX()) * (c.getY() - d.getY()) - (a.getY() - c.getY()) * (c.getX() - d.getX())) / denominator;
// 	Fixed u = ((a.getX() - c.getX()) * (a.getY() - b.getY()) - (a.getY() - c.getY()) * (a.getX() - b.getX())) / denominator;

// 	std::cout << "T: " << t << std::endl;
// 	std::cout << "U: " << u << std::endl;

// 	if (!(t <= 1 && t >= 0 && u <= 1 && u >= 0))
// 		return (std::nullopt);

// 	Point	point((a.getX() + (t * (b.getX() - a.getX()))).toFloat(), (a.getY() + (t * (b.getY() - a.getY()))).toFloat());

// 	return (point);
// }

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Point	barycentre = getTriangleBarycentre(a, b, c);

// 	std::cout << "Barycentre: " << barycentre << std::endl;

// 	std::optional<Point>	interAB = findIntersection(barycentre, point, a, b);
// 	std::optional<Point>	interBC = findIntersection(barycentre, point, b, c);
// 	std::optional<Point>	interCA = findIntersection(barycentre, point, c, a);

// 	std::cout << "InterAB: " << interAB.has_value() << std::endl;
// 	std::cout << "InterBC: " << interBC.has_value() << std::endl;
// 	std::cout << "InterCA: " << interCA.has_value() << std::endl;

// 	if (!interAB && !interBC && !interCA)
// 		return (1);
// 	return (0);
// }

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Vecteurs
	Fixed v0x = c.getX() - a.getX();
	Fixed v0y = c.getY() - a.getY();
	Fixed v1x = b.getX() - a.getX();
	Fixed v1y = b.getY() - a.getY();
	Fixed v2x = point.getX() - a.getX();
	Fixed v2y = point.getY() - a.getY();

	// Produits scalaires
	Fixed dot00 = v0x * v0x + v0y * v0y;
	Fixed dot01 = v0x * v1x + v0y * v1y;
	Fixed dot02 = v0x * v2x + v0y * v2y;
	Fixed dot11 = v1x * v1x + v1y * v1y;
	Fixed dot12 = v1x * v2x + v1y * v2y;

	// Calculs barycentriques
	Fixed denom = dot00 * dot11 - dot01 * dot01;
	Fixed u = (dot11 * dot02 - dot01 * dot12) / denom;
	Fixed v = (dot00 * dot12 - dot01 * dot02) / denom;

	// Vérifier si le point est dans le triangle
	return (u >= 0 && v >= 0 && (u + v) < 1);
}

int main()
{
	Point p1(0, 0);
	Point p2(5, 0);
	Point p3(2, 5);
	Point p4(2, 4);

	std::cout << bsp(p1, p2, p3, p4) << std::endl;

	return 0;
}