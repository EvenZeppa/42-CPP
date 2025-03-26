#include "Point.hpp"
#include <iostream>
#include <optional>

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

	// Point à l'intérieur du triangle
	Point inside(2, 2);
	std::cout << "Point (2, 2) inside triangle: " << bsp(p1, p2, p3, inside) << std::endl;

	// Point à l'extérieur du triangle
	Point outside(6, 6);
	std::cout << "Point (6, 6) outside triangle: " << bsp(p1, p2, p3, outside) << std::endl;

	// Point sur un bord du triangle
	Point onEdge(2.5, 2.5);
	std::cout << "Point (2.5, 2.5) on edge of triangle: " << bsp(p1, p2, p3, onEdge) << std::endl;

	// Point sur un sommet du triangle
	Point onVertex(0, 0);
	std::cout << "Point (0, 0) on vertex of triangle: " << bsp(p1, p2, p3, onVertex) << std::endl;

	return 0;
}