#include "student.h"
void person :: Show()
{
	printf("%s(%d)", name, age);
}

void student::Show() // ex. 김용철(28) 기계공학과(3학년)
{
	((person*)this)->Show(); // 김용철(28)
	printf(" : %s(%d학년)\n", major, grade); // : 기계공학과(3학년)
	
	for (int i = 0; i < SubNum; i++)
	{
		printf("과목명 : %s 점수 : %d\n", sub[i].Name(), sub[i].score);
	}
}