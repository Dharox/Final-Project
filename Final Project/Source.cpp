/*
Daniel Breslin
CIS 1202.R02
Final Project
Due 5/8/2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Employee_C.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
	int numEmployees = 0;
	int* numEmployees_p = &numEmployees;
	int index = -1;
	string fileName;

	cout << "Please enter a file name: ";
	cin >> fileName;

	Employee_C *employees = Fill_Array(numEmployees_p);

	return 0;
}

Employee_C* Fill_Array(int* numEmployees_p)
{
	Employee_C *employees = new Employee_C[100];
	bool repeat = true;
	bool valid = false;
	int nameSize;

	char name[SIZE];
	int ID;
	char gender;
	float salary;

	while (repeat)
	{
		cout << "\nPlease enter the prompted information for employee " << *numEmployees_p << ": ";
		cout << "\nEmployee Full Name: ";
		cin.get(name, SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!valid)
		{
			cout << "\nEmployee ID# (must be a 6 digit number, cannot start with 0): ";
			cin >> ID;
		
			if (ID >= 100000 && ID <= 999999)
			{
				valid = true;
			}
			else
			{
				cout << "\nInvalid number, please try again.";
			}
		}

		cout << "\nEmployee Gender (1 letter): ";
		cin >> gender;

		cout << "\nEmployee Salary: ";
		cin >> salary;

		nameSize = strlen(name);
		employees[*numEmployees_p].Set_FullName(name, nameSize);
		employees[*numEmployees_p].Set_EmployeeID(ID);
		employees[*numEmployees_p].Set_Gender(gender);
		employees[*numEmployees_p].Set_Salary(salary);

		*numEmployees_p++;

		cout << "\nWould you like to enter another employee? Enter 1 for yes and 0 for no: ";
		cin >> repeat;
	}


	return employees;
}

void Extract_ID()
{



}

void Find_Employee(int index)
{



}
