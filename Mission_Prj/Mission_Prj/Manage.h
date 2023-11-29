//직원 관리 시스템 :
//목표: 클래스 상속을 사용하여 직원 계층 구조 만들기
//
//구현 : Employee라는 기본 클래스를 만들고, Manager와 Developer 등의 파생 클래스를 만들어 보세요.각 클래스에는 직원 정보를 출력하는 가상 함수가 있어야 합니다.
//
//설명 : Employee 클래스를 만들고, Manager와 Developer 등의 파생 클래스를 생성하여 직원들의 정보를 다룹니다.가상 함수를 이용하여 각 직원의 정보를 출력하는 함수를 작성하세요.
#include <iostream>
#include <string.h>
class employee
{
private:
	char* name = nullptr;
	int age;
public:
	employee(const char* _name, int _age)
	{
		age = (_age);
		int name_length = strlen(_name) + 1;
		name = new char[name_length]; // 이름 길이
		strcpy_s(name, name_length, _name);
	}
	~employee()
	{
		if (name) delete name;
	}
	void Show()
	{
		printf("%s(%d)", name, age);
	}
};

class manager : public employee 
{
private:
	char* part = nullptr;
public:
	manager(const char* _name, int _age, const char* _part) :employee(_name, _age)
	{
		repart(_part);
	}
	manager& repart(const char* _part)
	{
		if (part) delete part;
		int part_length = strlen(_part)+1;
		part = new char[part_length];
		strcpy_s(part, part_length, _part);
		return *this;
	}
	void Show()
	{
		((employee*)this)->Show();
		printf("부서 : %s\n", part);
	}
};