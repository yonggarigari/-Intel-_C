#pragma once
#include <iostream>
#define	ABS(x) (((x)<0)?(-(x)):(x))
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
class Point
{
private:
public:
	int x;
	int y;
	Point* p1 = NULL;

	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)
	{
		//std::cout << "Point 생성(" << x << "," << y << ")\n"; // 생성자 함수 실행시 표시
	}
	~Point()
	{
		//std::cout << "Point 소멸(" << x << "," << y << ")\n"; // 소멸자 함수 실행시 표시
		//if (p1 != NULL) delete p1; // 연산자 operator+ 에서 반환된 'new' 값  해제
	}

	double Dist(Point p);		// Distance
	void Show(const char* s = NULL);  // View Current Point, s:Point name
	void ShowEx(const char* s = NULL);  // View Current Point, no Linefeed


	Point& operator+(Point p);


};

class Rect
{
public:
	Point p1, p2;
	int x1, x2, y1, y2; // Rect의 x좌표, y좌표 설정.

	Point LL, LR, UL, UR;

	void Init()
	{
		LL = Point(MIN(p1.x, p2.x), MIN(p1.y, p2.y));
		LR = Point(MAX(p1.x, p2.x), MIN(p1.y, p2.y));
		UL = Point(MIN(p1.x, p2.x), MAX(p1.y, p2.y));
		UR = Point(MAX(p1.x, p2.x), MAX(p1.y, p2.y));

	}
	Rect(Point pp1, Point pp2) : p1(pp1), p2(pp2),
		x1(pp1.x), y1(pp1.y), x2(pp2.x), y2(pp2.y)
	{
		Init();
	}
	Rect(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0)
	{
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;

		p1 = Point(_x1, _y1);
		p2 = Point(_x2, _y2);

		Init(); // Init 는 클래스내부에서만 사용. 
	}
	double Area();
	Rect& Show(const char* s);  // 형태 : Rect(p1(x,y), p2(x1,y1))
	Rect operator+(Rect r); // reference 하는 이유 : 
	Rect& operator-(Rect r);
	double operator*(Rect r);

};