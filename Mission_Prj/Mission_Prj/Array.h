#pragma once
/*
배열 합과 평균 :
목표: 배열의 합과 평균을 계산하는 함수 작성

구현 : 정수로 구성된 배열을 받아 해당 배열의 합과 평균을 계산하는 함수를 작성하세요.
*/
#include <iostream>

template<typename T>
class Array
{
private:
	int len;
	T* arr;
public:
	Array(int size)
	{
		len = size;
		arr = new T[size];
		//printf("생성\n");
	}
	~Array()
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
	T sum()
	{
		T hap = 0;
		for (int i = 0; i < len; i++)
		{
			hap += arr[i];
		}
		return hap;
	}
	T avg()
	{
		T _avg = sum() / len;
		return _avg;

	}


};