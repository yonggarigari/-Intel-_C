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
	this->x = x; this->y = y; // 'this' 셀프포인터 사용. this -> x 의 x는 맴버변수를 지칭
	return *this;
}
Point& Point::operator+(Point p) // 두점 curP와 p의 +연산결과를 (새로운 Point로) 반환
{
	Point* p1 = new Point(x + p.x, y + p.y);
	return *p1;
}
Point& Point :: operator++() // 객체 선행 연산자 오버로딩
{
	x++; y++;
	return *this;
}
Point& Point :: operator++(int) // 객체 후행 연산자 오버로딩
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
Point& Point::ViewP(const char* s) // NULL은 프로토타입에서만 정의
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
