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
		arr = new int[size];// int �� �迭�� ���� arr�� ��´�.
	}
	~ArrTest() //new �����߱� ������ �ݵ�� �Ҹ��� ����
	{
		delete arr;
	}
	int length()
	{
		return len;
	}
	int& operator[](int idx) // ����(calling sequence) : arr[n]
	{
		if (idx<0 || idx>len - 1) {
			printf("Out of bound\n");
			exit(1);// ���α׷� ���� �Լ�
		}
		return arr[idx]; // �迭 Ÿ��
		//return *(arr + idx); // ������ Ÿ��

	}
	void show(void) // ��� ���� : { 1, 2, 3, 4, 5, 11, 12, 13, 14, 15 }
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
	ArrTest& append(int size) // size : �߰��� ũ�� 
	{

		int* arr1 = new int[len + size]; // �ٽ� ���Ӱ� ���� -> �����̴� ���亸�ٴ� ������ �����ϰ� �ٽ� ���Ӱ� �����ϴ� ������.
		memcpy(arr1, arr, len * sizeof(int));
		delete arr;// ������ �����Ȱ� ����
		arr = arr1;
		len += size;

		return *this;
	}
	ArrTest& append(ArrTest& brr) // ��ü�� ������ ����� ���� �ݵ�� �������·� ����� ��.
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
