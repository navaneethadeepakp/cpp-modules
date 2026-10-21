#include "Point.hpp"

Fixed getArea(Point const a, Point const b, Point const p)
{
	Fixed val = (a.getX() - p.getX()) * (b.getY() - p.getY()) - (a.getY() - p.getY()) * (b.getX() - p.getX());
	if (val < Fixed(0))
		return (val * Fixed(-1));
	return val;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = getArea(a,b,c);
	Fixed area1 = getArea(a,b,point);
	Fixed area2 = getArea(b,c,point);
	Fixed area3 = getArea(c,a,point);

	if (area1 == 0 || area2 == 0 || area3 == 0) 
		return false;
	return (area1 + area2 + area3) == totalArea;
}