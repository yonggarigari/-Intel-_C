#pragma once
#include <iostream>

class Point
{
private: // default이긴 하나, 명시적으로 표시함.
	int x, y;
public:

	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)// 생성자 형성 (객체화 해주기 위해서 실시)
	{
	}
	Point& SetP(Point P); // self-reference
	Point& SetP(int x, int y);
	double Dist(Point p); // 함수호출
	Point& ViewP(const char* s = NULL); // View Current Point// NULL은 프로토타입에서만 정의
	Point& MoveP(int off_x, int off_y); // Move Point Position 
	int X() { return x; }; // private 영역에 맴버변수가 있을 경우, 외부영역에서 맴버변수를 확인하는 함수(단방향 - 값을 수정할 수 없음)
	int Y() { return y; };
	int& X1() { return x; }; // 참조를 활용하여 private 영역에 있는 맴범변수 수정하게 해줌.(양방향)
};
