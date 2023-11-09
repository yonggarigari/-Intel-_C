#include "Point.h"
#define ABS(x) ((x<0)?-(x):(x))

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
Point& Point::operator+(Point p) // ���� curP�� p�� +�������� (���ο� Point��) ��ȯ
{
	Point* p1 = new Point(x + p.x, y + p.y);
	return *p1;
}
Point& Point :: operator++() // ��ü ���� ������ �����ε�
{
	x++; y++;
	return *this;
}
Point& Point :: operator++(int) // ��ü ���� ������ �����ε�
{
	Point* p1 = new Point(x++, y++);
	return *p1;
}
double Point :: operator*(Point p)
{
	int w = ABS(x - p.x);
	int h = ABS(y - p.y);
	double a = w * h;
	return a;
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
Point3D& Point3D::SetP(Point3D p)
{
	X() = p.X(); Y() = p.Y(); z = p.z;
	return *this;
}
