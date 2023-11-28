// istream, ostream, iostream -> 입출력 시스템
// friend 선언
// string

#include <iostream>

using namespace std;

template<typename T>
class ArrTest
{
private:
	T* arr;
	int len;
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
	ArrTest<T>& append(ArrTest<T>& brr) // 객체를 변수로 사용할 때는 반드시 참조형태로 해줘야 함.
	{
		T* arr1 = new T[this->len + brr.length()];
		memcpy(arr1, arr, len * sizeof(T));
		memcpy(arr1 + len, brr.arr, brr.length() * sizeof(T));
		delete arr;
		arr = arr1;
		len += brr.length();

		return *this;
	}
	ArrTest<T>& operator+(ArrTest<T>& br)
	{
		int l = len + br.length();
		ArrTest<T>* cr = new ArrTest<T>(l);
		memcpy(cr->arr, arr, len * sizeof(T));
		memcpy(cr->arr + len, br.arr, br.length() * sizeof(T));

		return *cr;
	}
	ArrTest<T>& operator+=(ArrTest<T>& br)
	{
		return this->append(br);
	}
	bool operator==(ArrTest<T>& br) // bool은 true 혹은 false 을 출력하는 함수
	{
		if (len != br.len) return false;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] != br[i]) return false;
			else return true;
		}
	}
	void show(void)
	{
		int i;
		printf("{");
		for (i = 0; i < len - 1; i++)
		{
			std::cout << arr[i] << ",";
		}
		std::cout << arr[i];
		printf("}\n");
	}

	// std::cout<<arr[i]<<","; 
	friend ostream& operator<<(ostream& os, ArrTest& _arr) // ostream은 std 안에 포함되므로 위에 std 선언해줘야 함. 
		// 혹은 ostream 앞에다 'std::ostream' 형태로 해줘야 함.
	{
		int i;
		printf("{");
		for (i = 0; i < _arr.len - 1; i++)
		{
			std::cout << _arr.arr[i] << ",";
		}
		std::cout << _arr.arr[i];
		printf("}");

		return os;
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

class Point
{
private: // default이긴 하나, 명시적으로 표시함.
protected:
	int x;
	int y;
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)// 생성자 형성 (객체화 해주기 위해서 실시)
	{
	}
	Point& SetP(Point P)
	{
		x = P.x; y = P.y;
		return *this;
	}
	Point& SetP(int x, int y)
	{
		this->x = x; this->y = y;
		return *this;
	}
	double Dist(Point p)
	{
		int w = x - p.x;
		int h = y - p.y;

		return sqrt(pow(w, 2) + pow(h, 2));
	}

	Point& ViewP(const char* s = NULL)
	{
		printf("%s(%d, %d)\n", s, x, y);
		return *this;
	}
	Point& MoveP(int off_x, int off_y)
	{
		this->x = x + off_x; this->y = y + off_y;
		return *this;
	}
	int& X() { return x; }; 
	int& Y() { return y; };
	//int& X1() { return x; }; // 참조를 활용하여 private 영역에 있는 맴범변수 수정하게 해줌.(양방향)
	Point& operator+(Point p)
	{
		x++; y++;
		return *this;
	}
	double operator*(Point p)
	{
		int w = ABS(x - p.x);
		int h = ABS(y - p.y);
		double a = w * h;
		return a;
	}
	Point& operator++() 
	{
		x++; y++;
		return *this;
	}
	Point& operator++(int)
	{
		Point* p1 = new Point(x++, y++);
		return *p1;
	}
};
int main()
{
	//int a = 10; int b = 20;
	//printf("a=%d  b=%d\n", a, b);
	//Swap(a, b);
	//printf("a=%d  b=%d\n", a, b);
	//double a_1 = 2.4; double b_1 = 8.2;
	//printf("a=%.2f  b=%.2f\n", a_1, b_1);
	//Swap(a_1, b_1);
	//printf("a=%.2f  b=%.2f\n", a_1, b_1);

	int a1[] = { 1, 2, 3, 4, 5 };
	ArrTest<double> arr(5); // 클래스를 템플릿할 경우, main 에서 타입을 지정해줘야 함.
	for (int i = 0; i < 5; i++) { arr[i] = a1[i]; }

	int a2[] = { 11, 12, 13, 14, 15 };
	ArrTest<double> brr(5);
	for (int i = 0; i < 5; i++) { brr[i] = a2[i]; }

	if (arr == brr) printf("맞음");
	ArrTest<double> crr = arr + brr;

	std::cout << crr << "\n";
	std::cout << (arr += brr) << "\n";
	std::cout << (arr == brr) << "\n";

	string s = "hi my name";
	cout << s << "\n";
	cout << s.substr(3, 2) << "\n";
}

