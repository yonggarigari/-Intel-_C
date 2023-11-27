#pragma once
#include <istream>

class ArrTest
{
private:
	int len;
	int* arr;
public:
	ArrTest(int size) : len(size)
	{
		arr = new int[size];// int 형 배열로 만들어서 arr에 담는다.
	}
	~ArrTest() //new 생성했기 때문에 반드시 소멸자 생성
	{
		delete arr;
	}
	int length()
	{
		return len;
	}
	int& operator[](int idx) // 형태(calling sequence) : arr[n]
	{
		if (idx<0 || idx>len - 1) {
			printf("Out of bound\n");
			exit(1);// 프로그램 종료 함수
		}
		return arr[idx]; // 배열 타입
		//return *(arr + idx); // 포인터 타입

	}
	void show(void) // 출력 형태 : { 1, 2, 3, 4, 5, 11, 12, 13, 14, 15 }
	{
		int i;
		printf("{");
		for (i = 0; i < len-1; i++)
		{
			printf(" %d,", arr[i]);
		}
		printf(" %d ", arr[i]);
		printf("}\n");
	}
	ArrTest& append(int size) // size : 추가할 크기 
	{

		int* arr1 = new int[len + size]; // 다시 새롭게 생성 -> 덧붙이는 개념보다는 기존거 삭제하고 다시 새롭게 생성하는 개념임.
		memcpy(arr1, arr, len * sizeof(int));
		delete arr;// 기존에 생성된거 삭제
		arr = arr1;
		len += size;

		return *this;
	}
	ArrTest& append(ArrTest& brr) // 객체를 변수로 사용할 때는 반드시 참조형태로 해줘야 함.
	{
		int* arr1 = new int[this->len + brr.length()];
		memcpy(arr1, arr, len * sizeof(int));
		memcpy(arr1+ len, brr.arr, brr.length() * sizeof(int));
		delete arr;
		arr = arr1;
		len += brr.length();

		return *this;	
	}
};
