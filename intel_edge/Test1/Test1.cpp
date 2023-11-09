#include <iostream>
#include "Point.h"
int main() 
{
	Point p1(10, 20), p2, p3;
	p1.ViewP("P1"); // ""안에 들어가면 const으로 들어감. 그래서 const char임.
	p2.ViewP(); p3.ViewP();

	p2.SetP(Point(20, 30)).ViewP("P2"); // p2.SetP(Point(20, 30))에서 SetP 함수를 통해 Point로 리턴됨.
	p3.SetP(40, 50).ViewP("p3");
	//p1.ViewP("P1"); p2.ViewP("P2"); p3.ViewP("p3");
	printf("Point Move test..............\n");
	p1.MoveP(1, 1). ViewP("P1");
	p1.MoveP(1, 1). ViewP("P1");
	p1.MoveP(1, 1). ViewP("P1");
	p1.MoveP(1, 1). ViewP("P1");
	printf("Point Move test..............\n");

	printf("Point print...P1(%d %d)\n", p1.X(), p1.Y());
	p1.X() = 10; p1.Y() = 10;
	printf("Point print...)\n");  p1.ViewP("p1");

	Point p6 = p1 + p2;
	printf("Point [Operater+]Test---"); p6.ViewP("_p6");
	/*Point3D pp0, pp1(10, 20, 30);
	double d = pp1.Dist3D(pp0);
	double d1 = pp0.Dist(Point(10, 20));
	printf("pp0(0,0,0)과 pp1(10,20,30)의 거리 : %f", d);
	printf("pp0(0,0,0)과 p1(10,20)의 거리 : %f", d1);*/

}
