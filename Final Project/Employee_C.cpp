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

// Getters
char* Employee_C::Get_FullName() const
{
	return (char*) &fullName[0];
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
void Employee_C::Set_FullName(char fullName[])
{
	/*
	this->fullName[nameSize] = fullName[nameSize];
	*/ 

	int index = 0;
	while (fullName[index] != '\0' && index < SIZE - 1)
	{
		this->fullName[index] = fullName[index];
		index++;
	}

	this->fullName[index] = '\0';
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
	this->salary = salary;
	totalSalaries += salary;
}