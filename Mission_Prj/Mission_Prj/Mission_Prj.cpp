#include <iostream>
#include "Array.h"
#include "Manage.h"
#include "Max.h"

int main()
{
	
	
	// 배열 내 최대값 찾기
	/*
	double a1[] = { 2.3, 5.1, 5.4, 8.9, 8.98, 1.34 };
	Array_M<double> arr(6);
	for (int i = 0; i < arr.length(); i++)
	{
		arr[i] = a1[i];
		std::cout << " arr[" << i << "]:" << arr[i];
	}
	std::cout << "\n";
	std::cout << "최대값 : " << arr.Max();
	*/
	//직원 관리 시스템
	/*
	manager a("김용철", 28, "개발팀");
	a.Show();
	*/

	//배열의 합과 평균
	/* 
	double a1[] = {1.1, 2.3, 2.4}; 
	Array<double> arr(3);

	for (int i = 0; i < arr.length(); i++)
	{
		arr[i] = a1[i];
		std::cout << "arr[" << i << "]:" << arr[i];
	}
	
	std::cout << "\n";
	std::cout << "총합 : "<< arr.sum();
	std::cout << "\n";
	std::cout << "평균 : "<< arr.avg();
	*/
}
