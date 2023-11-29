//String  class :
//목표:  배열클래스를 이용한 문자열 처리 클래스 작성
//
//구현 : 문자열을 다루른 데 적합한 String 클래스를 만들고, 연산자를 오버로딩하여 문자열에 대한 연산을 수행하세요.
//
//설명 : +, << , != , == , += 연산자 오버로딩.찾기, 자르기, 바꾸기 연산 수행

#include <iostream>

class String
{
private:
	char* string_content;
	int len;
public:
	String(const char* str) // 문자열 생성자
	{
		len = strlen(str);
		string_content = new char[len];

		for (int i = 0; i < len; i++)
		{
			string_content[i] = str[i];
		}
	}
	~String()
	{
		delete string_content;
	}

	int length()
	{
		return len;
	}

	void show()
	{
		for (int i = 0; i < len; i++)
		{
			std::cout << string_content[i];
		}
	}
};