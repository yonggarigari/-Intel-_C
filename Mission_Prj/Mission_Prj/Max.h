//템플릿 함수 최대값 찾기 :
//목표: 템플릿 함수를 사용하여 배열의 최대값을 찾는 프로그램 작성
//
//구현 : 정수, 실수 또는 다른 자료형의 배열에서 최대값을 찾는 템플릿 함수를 작성하세요.
//
//설명 : 템플릿 함수를 사용하여 배열의 최대값을 찾는 프로그램을 작성합니다.다양한 자료형에 대해 동작하는 일반적인 함수를 구현합니다.
#include <iostream>

template <typename T>
class Array_M
{
private:
	T* arr;
	int len;
public:
	Array_M(int size)
	{
		len = size;
		arr = new T[size];
		//printf("생성\n");
	}
	~Array_M()
	{
		delete arr;
		//printf("소멸\n");
	}
	T& operator[](int idx) // 형태(calling sequence) : arr[n]
	{
		if (idx<0 || idx>len - 1) {
			printf("Out of bound\n");
			exit(1);// 프로그램 종료 함수
		}
		return arr[idx]; // 배열 타입
	}
	int length()
	{
		return len;
	}
	T Max()
	{
		T check = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] > check) {
				check = arr[i];
			}
		}
		return check;
	}
};