/*23.11.02
이전 수업 내용 : 
생성자도 함수이므로 오버로딩이 가능.
이니셜라이저는 C++ 기반의 특징 중 하나. ex) 'x = 10' == 'x(10)'
ex)
int a(10), b(20); // 이니셜라이즈는 변수 초기화에만 가능.
    //a = 10; b = 20;
    printf("초기값 a = %d  b = %d\n", a, b); // a=10, b=20
    printf("변수 a = %d  b = %d\n", a = 16, b = 25); // a=16  b=25
    // 함수 입력식 안에 a, b 값 변경 가능, but 'a(16), b(25)' 이런 형태는 사용 불가. 오직 변수 초기화에만 가능

오늘 수업 내용 : 
- Reference 
value 와 포인터 중간 어디쯤의 역할.
swap 함수를 이용해서 고찰
*/
#include <iostream>

#define SQUARE(x) x*x // 매크로함수 선언

#define ABS(x) ((x<0)?-(x):(x)) // 절대값이 나오는  매크로함수 선언
// 삼항연산자 = (조건식)?A:B -> 조건식 만족하면 A, 아니면 B

class Point
{
public:
    int x;
    int y;
    // 생성자 정의. 함수적 특성(디퐅트, 오버로드 등)
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) // x1을 x라 해도 무관. 이유는 괄호 앞 x을 맴버변수, 괄호 안 x을 생성자 변수로 컴퓨터가 알아서 잘 처리함.
    {
        //x = x1; y = y1; 
    }
    double Dist(Point p) // 거리측정함수
     {
    int w = x - p.x;
    int h = y - p.y;
    double d = sqrt(w * w + h * h);

    return d;
	}
    double area(Point p) // 넓이 측정 함수
    {
        int w = ABS(x - p.x);
        int h = ABS(y - p.y);
        double a = w * h;

        return a;
    }
    double Dist(int x1, int y1) // 거리측정함수_함수의 오버로딩 확인
    {
        int w = x - x1;
        int h = y - y1;
        double d = sqrt(w * w + h * h);

        return d;
    }
    double Dist(Point p1, Point p2) // 거리측정함수
    {
        int w = (p1.x - p2.x);
        int h = (p1.y - p2.y);
        double d = sqrt(w * w + h * h);

        return d;
    }
};


void printP(Point p)
{
    printf("point(%d %d)\n", p.x, p.y);
}

void swap_v(int a, int b) // call-by-Value
{
    int temp(a);
    printf("[swap_v]초기값  a = %d  b = %d\n", a, b);
    a = b; b = temp;
    printf("[swap_v]결과값  a = %d  b = %d\n", a, b);
}

void swap_p(int *a, int *b) // call-by-Reference 
// ex. a 주소 = 100, b 주소 = 101
//     a의 값 = 10,  b의 값 = 20
{
    int temp(*a); // temp = (a 주소)의 값 
    printf("[swap_p]초기값  a = %d  b = %d\n", *a, *b);
    *a = *b; *b = temp;
    printf("[swap_p]결과값  a = %d  b = %d\n", *a, *b);
}
int main()
{

   /* Point p1(10, 10), p2(20, 30), p3;

    double d = p1.Dist(p2);
    double a = p1.area(p2);
    double d1 = p1.Dist(p1, p2);*/

    int a(10), b(20); 
    //a = 10; b = 20;
    printf("초기값 a = %d  b = %d\n", a, b); 
    swap_v(a, b);
    printf("[swqp_v] 결과값 a = %d  b = %d\n", a, b); // a=10, b=20 
	swap_p(&a, &b);
	printf("[swqp_p] 결과값 a = %d  b = %d\n", a, b); 
}