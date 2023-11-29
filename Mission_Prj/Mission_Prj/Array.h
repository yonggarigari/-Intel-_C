#pragma once
/*
�迭 �հ� ��� :
��ǥ: �迭�� �հ� ����� ����ϴ� �Լ� �ۼ�

���� : ������ ������ �迭�� �޾� �ش� �迭�� �հ� ����� ����ϴ� �Լ��� �ۼ��ϼ���.
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
		//printf("����\n");
	}
	~Array()
	{
		delete arr;
		//printf("�Ҹ�\n");
	}
	T& operator[](int idx) // ����(calling sequence) : arr[n]
	{
		if (idx<0 || idx>len - 1) {
			printf("Out of bound\n");
			exit(1);// ���α׷� ���� �Լ�
		}
		return arr[idx]; // �迭 Ÿ��

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