/*
Daniel Breslin
CIS 1202.R02
Final Project
Due 5/8/2022
*/

#ifndef Employee_C_
#define Employee_C_

const int SIZE = 55; // constant int NAME_SIZE defined for fullName c-string

class Employee_C
{
private:
	char fullName[SIZE];
	int employeeID;
	float salary;
	char gender;

	static double totalSalaries;

public:
	Employee_C(); // Default constructor

	// Getters
	char* Get_FullName() const;
	int Get_EmployeeID() const;
	float Get_Salary() const;
	char Get_Gender() const;
	double Get_TotalSalaries() const;

	// Setters
	void Set_FullName(char fullName[]);
	void Set_EmployeeID(int employeeID);
	void Set_Salary(float salary);
	void Set_Gender(char gender);

};

#endif