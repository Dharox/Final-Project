/*
Daniel Breslin
CIS 1202.R02
Final Project
Due 5/8/2022
*/

#include "Employee_C.h"
#include <cstring>

double Employee_C::totalSalaries = 0.0;

Employee_C::Employee_C()
{
	fullName[0] = ' ';
	employeeID = 100000;
	salary = 0.0f;
	gender = 'N';
}

Employee_C::Employee_C(char fullName[], int nameSize, int employeeID, float salary, char gender)
{
	this->fullName[nameSize] = fullName[nameSize];
	this->employeeID = employeeID;
	this->salary = salary;
	this->gender = gender;

	totalSalaries += salary;
}

// Getters
char Employee_C::Get_FullName(int nameSize) const
{
	return fullName[nameSize];
}

int Employee_C::Get_EmployeeID() const
{
	return employeeID;
}

float Employee_C::Get_Salary() const
{
	return salary;
}

char Employee_C::Get_Gender() const
{
	return gender;
}

double Employee_C::Get_TotalSalaries() const
{
	return totalSalaries;
}

// Setters
void Employee_C::Set_FullName(char fullName[], int nameSize)
{
	this->fullName[SIZE] = fullName[SIZE];
}

void Employee_C::Set_EmployeeID(int employeeID)
{
	this->employeeID = employeeID;
}

void Employee_C::Set_Gender(char gender)
{
	this->gender = gender;
}

void Employee_C::Set_Salary(float salary)
{
	totalSalaries -= salary;
	this->salary = salary;
	totalSalaries += salary;
}