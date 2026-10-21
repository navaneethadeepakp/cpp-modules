#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const n1, float const n2);
		Point(const Point &src);
		Point &operator=(const Point &rhs);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif