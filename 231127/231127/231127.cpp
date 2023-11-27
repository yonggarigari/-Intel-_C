//배열 클래스
//배열 요소에 추가

#include <iostream>
#include "ArrTest.h"

class Func
{
public:
	int operator() (int a, int b)
	{
		return a * b;
	}
	double operator() (double a, double b)
	{
		return a * b;
	}
	ArrTest& operator()(ArrTest& b1, ArrTest& b2)
	{
		return b1.append(b2);
	}

};
int main()
{
	/* <배열클래스>
	int a1[] = { 1, 2, 3, 4, 5 };
	ArrTest arr(7);
	for (int i = 0; i < 5; i++) { arr[i] = a1[i]; }

	for (int i = 0; i < arr.length(); i++) // arr의 배열 크기로 설정 가능
	{
		printf("ArrTest[%d] : %d\n", i, arr[i]);
	}

	int a2[] = { 11, 12, 13, 14, 15 };
	ArrTest brr(7);
	for (int i = 0; i < 5; i++) { brr[i] = a2[i]; }
	int n = arr.length();
	printf("배열 확장 %d---->%d\n", n, arr.append(10).length());
	//int a2[] = { 11, 12, 13, 14, 15 };
	//int n = arr.length();
	//printf("배열 확장 %d---->%d\n", n, arr.append(10).length());
	//for (int i = 5; i < 10; i++)
	//{
	//	arr[i] = a2[i - 5];
	//}
	//for (int i = 0; i < arr.length(); i++) // arr의 배열 크기로 설정 가능
	//{
	//	printf("ArrTest[%d] : %d\n", i, arr[i]);
	//}
	*/

	/* <연산자 오버로딩>
	int a1[] = { 1, 2, 3, 4, 5 };
	ArrTest arr(5);
	for (int i = 0; i < 5; i++) { arr[i] = a1[i]; }
	
	int a2[] = { 11, 12, 13, 14, 15 };
	ArrTest brr(5);
	for (int i = 0; i < 5; i++) { brr[i] = a2[i]; }
	
	Func mul;
	std::cout << mul(2, 3);
	mul(arr, brr).show();
	*/
}

