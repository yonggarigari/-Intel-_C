#pragma once
#include <iostream>

class Point
{
private: // default이긴 하나, 명시적으로 표시함.
protected:
	int x;
	int y;
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)// 생성자 형성 (객체화 해주기 위해서 실시)
	{
	}
	Point& SetP(Point P); // self-reference
	Point& SetP(int x, int y);
	double Dist(Point p); // Distance, 함수호출
	
	Point& ViewP(const char* s = NULL); // View Current Point// NULL은 프로토타입에서만 정의
	Point& MoveP(int off_x, int off_y); // Move Point Position 
	int& X() { return x; }; // private 영역에 맴버변수가 있을 경우, 외부영역에서 맴버변수를 확인하는 함수(단방향 - 값을 수정할 수 없음)
	int& Y() { return y; };
	//int& X1() { return x; }; // 참조를 활용하여 private 영역에 있는 맴범변수 수정하게 해줌.(양방향)
	Point& operator+(Point p);
	double operator*(Point p); // 두 점이 이루는 사각형의 넓이
	Point& operator++(); // 선행 연산자
	Point& operator++(int); // 후행 연산자
};

class Point3D : public Point
{
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) // 상위클래스의 생성자 호출
	{}
	Point3D& SetP(Point3D p);
	double Dist3D(Point3D p) // 3D 거리측정함수
	{
		int w = X() - p.X(); // x, y가 private 영역일 때 이 방법으로 호출
		int h = y-p.y;
		int d = z - p.z;

		return sqrt(pow(w, 2) + pow(h, 2) + pow(d, 2));
	}
};