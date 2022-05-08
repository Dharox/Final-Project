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
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

Employee_C* Fill_Array(int* numEmployees_p);
void Extract_ID(fstream& binaryOut, int* numEmployees_p, Employee_C* employees, string fileName);
void Find_Employee(int* index_p, int idNum, int numEmployees, fstream& binaryIn);
void Validate_Index(int index, int numEmployees);

int main()
{
	int numEmployees = 0;
	int* numEmployees_p = &numEmployees;
	int index = -1;
	int* index_p = &index;
	string fileName;
	bool loop = true;

	cout << "Please enter a file name: ";
	cin >> fileName;

	fstream binaryOut;

	Employee_C* employees = Fill_Array(numEmployees_p);

	Extract_ID(binaryOut, numEmployees_p, employees, fileName);

	fstream binaryIn(fileName, ios::in | ios::binary);
	if (binaryIn.fail())
	{
		cout << "\nFile not found, program will end.";

		system("pause");
		return 0;
	}

	int idNum;
	while (loop)
	{
		index = -1;
		cout << "\nPlease enter the employee ID you are searching for: ";
		cin >> idNum;

		Find_Employee(index_p, idNum, numEmployees, binaryIn);

		try
		{
			Validate_Index(index, numEmployees);
			
			cout << setprecision(2) << fixed;
			cout << "\nEmployee Found: ";
			cout << "\nEmployee Full Name: " << employees[index].Get_FullName();
			cout << "\nEmployee ID#: " << employees[index].Get_EmployeeID();
			cout << "\nEmployee Gender: " << employees[index].Get_Gender();
			cout << "\nEmployee Salary: $" << employees[index].Get_Salary();
			cout << "\nTotal Employee Salaries: $" << employees[index].Get_TotalSalaries();
		}
		catch (string invalidIndexException)
		{
			cout << invalidIndexException;
		}

		cout << "\nWould you like to search for another employee? Enter 1 for yes and 0 for no: ";
		cin >> loop;
	}

	binaryIn.close();

	return 0;
}

Employee_C* Fill_Array(int* numEmployees_p)
{
	Employee_C *employees = new Employee_C[100];
	bool repeat = true;
	bool valid = false;

	char name[SIZE];
	int ID;
	char gender;
	float salary;

	while (repeat)
	{
		cin.ignore();
		cout << "\nPlease enter the prompted information for employee " << ((*numEmployees_p) + 1) << ": ";
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

		employees[*numEmployees_p].Set_FullName(name);
		employees[*numEmployees_p].Set_EmployeeID(ID);
		employees[*numEmployees_p].Set_Gender(gender);
		employees[*numEmployees_p].Set_Salary(salary);

		cout << "\nWould you like to enter another employee? Enter 1 for yes and 0 for no: ";
		cin >> repeat;

		(*numEmployees_p)++;
		valid = false;
	}

	return employees;
}

void Extract_ID(fstream &binaryOut, int* numEmployees_p, Employee_C* employees, string fileName)
{
	binaryOut.open(fileName, ios::out | ios::binary);
	
	for (int i = 0; i < *numEmployees_p; i++)
	{
		int idNum = employees[i].Get_EmployeeID();
		binaryOut.write(reinterpret_cast<char*>(&idNum), sizeof(idNum));
	}

	binaryOut.close();
}

void Find_Employee(int* index_p, int idNum, int numEmployees, fstream &binaryIn)
{
	int idHolder = 100000;
	vector<int> ids;

	binaryIn.clear();
	binaryIn.seekg(0, ios::beg);

	for (int i = 0; i < numEmployees; i++)
	{
		binaryIn.read(reinterpret_cast<char*>(&idHolder), sizeof(idHolder));
		ids.push_back(idHolder);
	}

	for (int j = 0; j < numEmployees; j++)
	{
		if (ids[j] == idNum)
		{
			*index_p = j;
		}
	}
}

void Validate_Index(int index, int numEmployees)
{
	string invalidIndexException = "\nError: index falls outside the range of employees.";

	if (index > numEmployees || index < 0)
	{
		throw invalidIndexException;
	}
}
