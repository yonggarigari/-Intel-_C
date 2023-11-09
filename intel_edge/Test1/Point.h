#pragma once
#include <iostream>

class Point
{
private: // default�̱� �ϳ�, ��������� ǥ����.
protected:
	int x;
	int y;
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)// ������ ���� (��üȭ ���ֱ� ���ؼ� �ǽ�)
	{
	}
	Point& SetP(Point P); // self-reference
	Point& SetP(int x, int y);
	double Dist(Point p); // Distance, �Լ�ȣ��
	
	Point& ViewP(const char* s = NULL); // View Current Point// NULL�� ������Ÿ�Կ����� ����
	Point& MoveP(int off_x, int off_y); // Move Point Position 
	int& X() { return x; }; // private ������ �ɹ������� ���� ���, �ܺο������� �ɹ������� Ȯ���ϴ� �Լ�(�ܹ��� - ���� ������ �� ����)
	int& Y() { return y; };
	//int& X1() { return x; }; // ������ Ȱ���Ͽ� private ������ �ִ� �ɹ����� �����ϰ� ����.(�����)
	Point& operator+(Point p);
	double operator*(Point p); // �� ���� �̷�� �簢���� ����
	Point& operator++(); // ���� ������
	Point& operator++(int); // ���� ������
};

class Point3D : public Point
{
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) // ����Ŭ������ ������ ȣ��
	{}
	Point3D& SetP(Point3D p);
	double Dist3D(Point3D p) // 3D �Ÿ������Լ�
	{
		int w = X() - p.X(); // x, y�� private ������ �� �� ������� ȣ��
		int h = y-p.y;
		int d = z - p.z;

		return sqrt(pow(w, 2) + pow(h, 2) + pow(d, 2));
	}
};