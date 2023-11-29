//���ø� �Լ� �ִ밪 ã�� :
//��ǥ: ���ø� �Լ��� ����Ͽ� �迭�� �ִ밪�� ã�� ���α׷� �ۼ�
//
//���� : ����, �Ǽ� �Ǵ� �ٸ� �ڷ����� �迭���� �ִ밪�� ã�� ���ø� �Լ��� �ۼ��ϼ���.
//
//���� : ���ø� �Լ��� ����Ͽ� �迭�� �ִ밪�� ã�� ���α׷��� �ۼ��մϴ�.�پ��� �ڷ����� ���� �����ϴ� �Ϲ����� �Լ��� �����մϴ�.
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
		//printf("����\n");
	}
	~Array_M()
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