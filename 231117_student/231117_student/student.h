#pragma once
#include <iostream>

class person
{
protected:
	char* name = nullptr;
	//char name[5]; // char : 1 ����Ʈ, �ѱ� : 2����Ʈ -> �ѱ� 2�ڸ� �Է� ����

public:
	int age;
	person(int _age = 0) : age(_age) {} // age = null�� �ʱ�ȭ.
	person(const char* Nam, int _age) // ������, Nam : �̸�, _age : ����
	{
		age = _age;
		rename(Nam);
		/*
		name = new char[strlen(Nam)+1]; // �迭�� ���������� ���� ����
		//name = new char[100]; // name ���� �ȿ� 100���� char�� ����.(heap ������ �Ҵ�)
		strcpy(name, Nam); // 'name = Nam' �� ����(�Է¹��� 'Nam'�� 'name'������ �ִ� ��)���� �����ؼ�
						   // �̵������� �ۼ��ϸ� �ϰ� ���ϴ� ���ڿ� ���簡 �ƴ� �̻��ϰ� ��.�׷��� strcpy �Լ��� ���.
		*/
	}
	person& rename(const char* Nam) // �̸� ���� // rename�� reference�� person ���·� ����.
	{
		if (name) delete name; // 'name' ���� ����� delete ����. // �̸� ������ ��� ������ ����� name ����. 
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);
		return *this;
	}
	void Show();
	~person() // �Ҹ���
	{
		if (name) delete name; // �����ڿ��� heap ������ �Ҵ�� 'name' ������ ���� 
		// �׳� delete name�ϸ� name�� ���� ��� ����ǹǷ� ������ �߻�
	}
};
class subject // (����, 50)/
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
	char* Name() { return (char*)name; } // private ������ 'name'�� �����ϱ� ���� �Լ�
};

class student : public person
{
	char* major = nullptr;

public:
	int grade;
	int SubNum = 0; // �������� ��
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

