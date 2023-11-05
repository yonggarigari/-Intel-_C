#include "Point.h"
double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;

	return sqrt(pow(w, 2) + pow(h, 2));
}

Point& Point::SetP(Point P)
{
	x = P.x; y = P.y;
	return *this;
}
Point& Point::SetP(int x, int y)
{
	this->x = x; this->y = y; // 'this' ���������� ���. this -> x �� x�� �ɹ������� ��Ī
	return *this;
}
Point& Point::ViewP(const char* s) // NULL�� ������Ÿ�Կ����� ����
{
	printf("%s(%d, %d)\n", s, x, y);
	return *this;
}
Point& Point::MoveP(int dx, int dy)
{
	this->x = x + dx; this->y = y + dy; // this-> x += dx; this-> += dy
	return *this;
}