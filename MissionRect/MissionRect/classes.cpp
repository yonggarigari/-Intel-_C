#include "Classes.h"
#define	ABS(x)	(((x)<0)?(-(x)):(x))
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))

double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
void Point::Show(const char* s)
{
	printf("%s(%d,%d)\n", s, x, y);
}
void Point::ShowEx(const char* s)
{
	//std::cout << s << "(" << x << "," << y << ")" << std::endl;
	printf("%s(%d,%d)", s, x, y);
}
Point& Point::operator+(Point p)  // ���� CurP�� p�� + �������� (���ο� Point��) ��ȯ
{
	Point* p1 = new Point(x + p.x, y + p.y);
	return *p1;
}

Rect& Rect::Show(const char* s)  // ���� : Rect(p1(x,y), p2(x1,y1))
{
	printf("%s(", s);
	LL.ShowEx("LL");
	UR.ShowEx("UR");
	printf(")\n");
	return *this;
}

double Rect::Area() // �Ű�����(argument) ��� ��
{
	return (double)(ABS((p1.x - p2.x) * (p1.y - p2.y)));
}

Rect Rect::operator+(Rect r) // ����(reference) �� �ص� �ǳ� �ϸ� ������ �������.
{
	int x1 = MIN(MIN(this->x1, this->x2), MIN(r.x1, r.x2)); // �Լ��� x1�� Ŭ���� x1�� ȥ���� �� �� �����Ƿ� Ŭ���� x1�� ����� ���� this �����͸� ���
	//int rx1 = MIN(MIN(x1, x2), MIN(r.x1, r.x2)); // �װ� ������ �Լ��� x1�� �ٸ� �̸����� ����
	int x2 = MAX(MAX(this->x1, this->x2), MAX(r.x1, r.x2));
	int y1 = MIN(MIN(this->y1, this->y2), MIN(r.y1, r.y2));
	int y2 = MAX(MAX(this->y1, this->y2), MAX(r.y1, r.y2));

	
	return Rect(x1, y1, x2, y2); // �׳� ��ȯ�ϸ� ���������� ���� ����ǹǷ� 'new'�� �̿��� �����Ҵ� �ϴ� ��.
}
Rect& Rect::operator-(Rect r)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	Rect& rr = *this; // this �����͸� rr�� ������.(reference)

	if (rr.LR.x<r.LL.x || rr.LL.x>r.LR.x || rr.UL.y<r.LL.y || rr.LL.y>r.UL.y) // ��ġ�� �ʴ� ����
	{
		//return NULL; // NULL�� ���� ������ �����Ƿ� ���� �߻�.
		return *(new Rect(0, 0, 0, 0)); // 0 Rect ��ȯ
	}
	x1 = MIN(MIN(rr.x1, r.x2), MIN(r.x1, r.x2));
	x2 = MAX(rr.LL.x, r.LL.x);
	x3 = MIN(rr.LR.x, r.LR.x);
	x4 = MAX(MAX(rr.x1, rr.x2), MAX(r.x1, r.x2));


	y1 = MIN(MIN(rr.y1, rr.y2), MIN(r.y1, r.y2));
	y2 = MIN(rr.UL.y, r.UL.y);
	y3 = MAX(rr.LL.y, r.LL.y);
	y4 = MAX(MAX(rr.y1, rr.y2), MAX(r.y1, r.y2));

	return *(new Rect(x2, y2, x3, y3));



}
double Rect::operator*(Rect r)
{

	double d1 = this->Area();
	double d2 = r.Area();
	double d3 = (*(this) - r).Area();
	return (d1 + d2) - d3;
}