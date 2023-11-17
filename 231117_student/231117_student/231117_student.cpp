#include <iostream>
#include "student.h"

int main()
{
   /* person p1("김용철", 28);
    p1.Show();
    p1.rename("무함마드김용철").Show();*/
    student _p1("김용철", 28, "기계공학", 3);
    _p1.Setsub("국어", 90); _p1.Show();
    _p1.Setsub("영어", 80); _p1.Show();
    _p1.Setsub("수학", 70); _p1.Show();
    _p1.Setsub("국어", 60); _p1.Show();
    _p1.Setsub("국어", 50); _p1.Show();
}
