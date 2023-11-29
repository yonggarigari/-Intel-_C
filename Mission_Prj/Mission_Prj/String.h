//String  class :
//��ǥ:  �迭Ŭ������ �̿��� ���ڿ� ó�� Ŭ���� �ۼ�
//
//���� : ���ڿ��� �ٷ縥 �� ������ String Ŭ������ �����, �����ڸ� �����ε��Ͽ� ���ڿ��� ���� ������ �����ϼ���.
//
//���� : +, << , != , == , += ������ �����ε�.ã��, �ڸ���, �ٲٱ� ���� ����

#include <iostream>

class String
{
private:
	char* string_content;
	int len;
public:
	String(const char* str) // ���ڿ� ������
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