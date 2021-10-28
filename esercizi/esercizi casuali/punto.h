#ifndef PUNTO_H
#define PUNTO_H

struct punto {int x;int y;};
#endif

#include <cmath>

double distanza(const punto& point1,const punto& point2)
{
	return sqrt(pow(point1.x - point2.x,2) + pow(point1.y - point2.y,2));
}

