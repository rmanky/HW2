#include "Point.h"

Point addPoint(int x, int y, int value) {
	Point newPoint;
	newPoint.x = x;
	newPoint.y = y;
	newPoint.value = value;

	return newPoint;
}
