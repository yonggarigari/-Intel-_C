#include "student.h"
void person :: Show()
{
	printf("%s(%d)", name, age);
}

void student::Show() // ex. ���ö(28) �����а�(3�г�)
{
	((person*)this)->Show(); // ���ö(28)
	printf(" : %s(%d�г�)\n", major, grade); // : �����а�(3�г�)
	
	for (int i = 0; i < SubNum; i++)
	{
		printf("����� : %s ���� : %d\n", sub[i].Name(), sub[i].score);
	}
}