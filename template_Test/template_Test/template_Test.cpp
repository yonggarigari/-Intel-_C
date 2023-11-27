#include <iostream>
template<typename T>
class ArrTest // class 정의에서 'template' 사용시 외부함수 선언할 경우 타입을 지정해줘야 함. 좀 복잡하니까 클래스 내부에 함수 선언하는게 편함.
{
private:
	T* arr;
	int len; // 배열 요소의 수 -> '정수'여야만 한다.
public:
	ArrTest(int size) : len(size)
	{
		arr = new T[size];
	}
	~ArrTest()
	{
		delete arr;
	}
	int length()
	{
		return len;
	}
	T& operator[](int idx)
	{
		if (idx<0 || idx>len - 1) {
			printf("Out of bound\n");
			exit(1);
		}
		return arr[idx]; 
		//return *(arr + idx); // 포인터 타입

	}
	void show(void)
	{
		int i;
		printf("{");
		for (i = 0; i < len - 1; i++)
		{
			std::cout<<arr[i]<<","; // cout은 별도의 타입을 지정 안 해줘도 알아서 타입에 맞게 출력해준다. 
		}
		std::cout<< arr[i];
		printf("}\n");
	}
	ArrTest& append(int size)
	{

		T* arr1 = new T[len + size];
		memcpy(arr1, arr, len * sizeof(T));
		delete arr;
		arr = arr1;
		len += size;

		return *this;
	}
	ArrTest& append(ArrTest& brr) 
	{
		T* arr1 = new T[this->len + brr.length()];
		memcpy(arr1, arr, len * sizeof(T));
		memcpy(arr1 + len, brr.arr, brr.length() * sizeof(T));
		delete arr;
		arr = arr1;
		len += brr.length();

		return *this;
	}
};
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
	ArrTest<int>& operator()(ArrTest<int>& b1, ArrTest<int>& b2) // class 정의에서 'template' 사용시 외부함수 선언할 경우 타입을 지정해줘야 함.
	{
		return b1.append(b2);
	}

};
template<typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename T>
T ABS(T a)
{
	if (a < 0)	return -a; return a;
	/*if (a < 0) { return -a; }
	else { return a; }*/
}

int main()
{
	int a = 10; int b = 20;
	printf("a=%d  b=%d\n", a, b);
	Swap(a, b);
	printf("a=%d  b=%d\n", a, b);

	double a_1 = 2.4; double b_1 = 8.2;
	printf("a=%.2f  b=%.2f\n", a_1, b_1);
	Swap(a_1, b_1);
	printf("a=%.2f  b=%.2f\n", a_1, b_1);

	int a1[] = { 1, 2, 3, 4, 5 };
	ArrTest<int> arr(5); // 클래스를 템플릿할 경우, main 에서 타입을 지정해줘야 함.
	for (int i = 0; i < 5; i++) { arr[i] = a1[i]; }

	int a2[] = { 11, 12, 13, 14, 15 };
	ArrTest<int> brr(5);
	for (int i = 0; i < 5; i++) { brr[i] = a2[i]; }

	Func mul;
	//std::cout << mul(2, 3);
	mul(arr, brr).show();
}

