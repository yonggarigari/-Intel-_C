//���� ���� �ý��� :
//��ǥ: Ŭ���� ����� ����Ͽ� ���� ���� ���� �����
//
//���� : Employee��� �⺻ Ŭ������ �����, Manager�� Developer ���� �Ļ� Ŭ������ ����� ������.�� Ŭ�������� ���� ������ ����ϴ� ���� �Լ��� �־�� �մϴ�.
//
//���� : Employee Ŭ������ �����, Manager�� Developer ���� �Ļ� Ŭ������ �����Ͽ� �������� ������ �ٷ�ϴ�.���� �Լ��� �̿��Ͽ� �� ������ ������ ����ϴ� �Լ��� �ۼ��ϼ���.
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
		name = new char[name_length]; // �̸� ����
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
		printf("�μ� : %s\n", part);
	}
};