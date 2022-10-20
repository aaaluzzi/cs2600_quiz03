//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

//gcc employeeMain.c employeeTable.c employeeTwo.c 
#include <string.h>
#include <stdlib.h>
#include "Employee.h"

PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
PtrToEmployee searchEmployeeByPhone(const Employee table[], int tableSize, char *targetPhone);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int tableSize, double targetSalary); 

int main(void) {
	//defined in employeeTable.c 

	extern Employee EmployeeTable[];
	extern const int EmployeeTableEntries;

	PtrToEmployee matchPtr;	//Declaration 

	//Example not found     
	matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

	if (matchPtr != NULL)
		printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee ID is NOT found in the record\n");

	//Example found 
	matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

	if (matchPtr != NULL)
		printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee Tony Bobcat is NOT found in the record\n");

    //Example found 
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");

	if (matchPtr != NULL)
		printf("Employee with number 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee with number 310-555-1215 is NOT found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 9.50);

	//Example not found 
	if (matchPtr != NULL)
		printf("Employee with salary of 9.50 is in the record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee with salary of 9.50 is NOT found in the record\n");
	return EXIT_SUCCESS;
}