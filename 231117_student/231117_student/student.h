#pragma once
#include <iostream>

class person
{
protected:
	char* name = nullptr;
	//char name[5]; // char : 1 바이트, 한글 : 2바이트 -> 한글 2자만 입력 가능

public:
	int age;
	person(int _age = 0) : age(_age) {} // age = null로 초기화.
	person(const char* Nam, int _age) // 생성자, Nam : 이름, _age : 나이
	{
		age = _age;
		rename(Nam);
		/*
		name = new char[strlen(Nam)+1]; // 배열을 가변적으로 생성 가능
		//name = new char[100]; // name 변수 안에 100개의 char형 생성.(heap 영역에 할당)
		strcpy(name, Nam); // 'name = Nam' 의 개념(입력받은 'Nam'을 'name'변수에 넣는 것)으로 접근해서
						   // 이딴식으로 작성하면 니가 원하는 문자열 복사가 아닌 이상하게 됨.그러니 strcpy 함수를 써라.
		*/
	}
	person& rename(const char* Nam) // 이름 수정 // rename을 reference로 person 형태로 받음.
	{
		if (name) delete name; // 'name' 값이 생기면 delete 실행. // 이름 변경할 경우 기존에 저장된 name 삭제. 
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);
		return *this;
	}
	void Show();
	~person() // 소멸자
	{
		if (name) delete name; // 생성자에서 heap 영역에 할당된 'name' 변수를 삭제 
		// 그냥 delete name하면 name에 값이 없어도 실행되므로 오류가 발생
	}
};
class subject // (수학, 50)/
{
private:
	char* name = NULL;
public:
	int score;
	subject() {};
	subject(const char* _name, int _score = 0) : score(_score)
	{
		reSub(_name);

	}
	subject& reSub(const char* _name)
	{
		if (name) delete name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		return *this;
	}
	char* Name() { return (char*)name; } // private 영역의 'name'을 참고하기 위한 함수
};

class student : public person
{
	char* major = nullptr;

public:
	int grade;
	int SubNum = 0; // 수강과목 수
	subject sub[10]; // kor, eng

	student(const char* Nam, int age, const char* _major, int _grade) : person(Nam, age)
	{
		remajor(_major);
		grade = _grade;
	}
	~student()
	{
		if (major) delete major;
	}

	student& remajor(const char* _major)
	{
		if (major) delete major;
		major = new char[strlen(_major) + 1];
		strcpy(major, _major);
		return *this;
	}
	void Show();
	void Setsub(const char* Nam, int sco)
	{
		if (SubNum > 10) { return; }
		sub[SubNum].reSub(Nam).score = sco;
		/*sub[idx].resub(Nam);
		  sub[idx].score = sco*/
		SubNum++;
	}

};

