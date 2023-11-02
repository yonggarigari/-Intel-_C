//클래스
#include <iostream>

#define SQUARE(x) x*x // 매크로함수 선언
// 함수의 오버로딩 조건(반환값은 동일한 형태)을 무시하는 특징이 있음
// 주의점 : 주변 요건으로 인해 오류가 발생할 수 있음
// 괄호를 집어넣어서 연산에 대해 정확하게 표기한다. ex)((x)*(x))
#define ABS(x) ((x<0)?-(x):(x)) // 절대값이 나오는  매크로함수 선언
// 삼항연산자 = (조건식)?A:B -> 조건식 만족하면 A, 아니면 B

class Point // 클래스 선언
{
public:
    int x; // 맴버변수
    int y; // 변수
    Point() {}// null argument 허용, null 값이어도 초기화 가능하게 해줌. Point(int x1= 0, y1 =0) 해도 같은 결과값
    Point(int x1, int y1) // 생성자는 class 함수랑 같은 이름이어야 함. 이 과정을 통해 객체 생성됨. 생성자도 함수의 일종이라 오버로딩(매개변수가 달라도 함수 실행 가능)이 가능함.
    {
        x = x1; y = y1; // 초기화 해줌.
    }
    double Dist(Point p); // 맴버함수  
    // Dist 함수 안에는 point 클래스 'p' 라는 점을 넣음
    double area(Point p);
    double Dist(int x1, int x2);
};

double Point::Dist(Point p) // 거리측정함수 // 클래스 내 함수를 정의할 때 '::' 표시. 
{
    int w = x - p.x; // x는 클래스의 x -> 클래스의 맴버변수를 지역변수처럼 사용 가능.
    int h = y - p.y;
    double d = sqrt(w * w + h * h);

    return d;
}
double Point::Dist(int x1, int y1) // 함수의 오버로딩 확인
{
    int w = x - x1; // x는 클래스의 x -> 클래스의 맴버변수를 지역변수처럼 사용 가능.
    int h = y - y1;
    double d = sqrt(w * w + h * h);

    return d;
}

double Point::area(Point p) // 넓이 측정 함수
{
    int w = ABS(x - p.x);
    int h = ABS(y - p.y);
    double a = w * h;

    return a;
}
/*
typedef struct Point // 구조체 선언
{
    int x;
    int y;
} Point2D;
double Dist(Point2D p1, Point2D p2); // 함수 호출
*/

int main()
{
    std::cout << "Hello! welcome to the C++ world\n";
    printf("안녕 이 세계에 온 걸 환영해\n\n");

    printf("2의 제곱: %d\n", SQUARE(2));
    printf("1.5의 제곱: %.3f\n", SQUARE(1.5));
    int x = 7;
    printf("%d의 제곱: %d\n", x, SQUARE(x));
    //int b;
    //scanf_s("%d", &b);
    printf("-5의 절대값 : %d\n", ABS(-5));
    printf("7의 절대값 : %d\n", ABS(7));
    printf("7의 절대값 : %d\n", ABS(7));

    Point p1(10, 10), p2(20, 30), p3; // 실인자를 넣어주면서(=초기화) p1, p2 객체화됨. 
    //Point2D p1, p2;
    //p1.x = 10; p1.y = 10;
    //p2.x = 20; p2.y = 30;

    double d = p1.Dist(p2); // p1의 객체 안 Dist 함수에 p2를 대입한다. p2를 구조체라고 생각하면 됨. p2.Dist(p1) 해도 같은 결과값 나옴.
    double a = p1.area(p2);

    printf("두점 p1(%d, %d), p2(%d, %d))의 넓이는 %.2f 입니다.\n",
        p1.x, p1.y, p2.x, p2.y, a);

    printf("두점 p1(%d, %d), p2(%d, %d))의 거리는 %.2f 입니다.\n",
        p1.x, p1.y, p2.x, p2.y, d);
    printf("null 값 P3는 p(%d, %d)로 설정되었습니다.\n", p3.x, p3.y);

    /*
    double d = Dist(p1, p2);
    printf("두점 p1(%d, %d), p2(%d, %d))의 거리는 %.2f 입니다.",
        p1.x, p1.y, p2.x, p2.y, d); // 구조체 이용
    */
}

//double Dist(Point2D p1, Point2D p2) // 두 점의 거리 값 측정 함수_구조체 이용
//{
//    int w = ABS(p1.x - p2.x);
//    int h = ABS(p1.y - p2.y);
//    int w1 = w * w;
//    int h1 = h * h;
//    double d = sqrt(w1+h1);
//
//    return d;
//}



