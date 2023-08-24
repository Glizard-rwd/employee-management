/*
 * This is the header file for the Employee class.
 * This file could be considered as "interface" of the class.
 * The function that the Employee class must have.
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
// Symbolic constant for income tax calculation
#define INCOME_TAX_PERCENT 15
#include <iostream>
using namespace std;
class Employee{
// Attributes
private:
// Dynamic buffer to store employee's name
    string *empName{};
// Employee's Id
    unsigned int empId{};
// Employee's annual salary in USD
    double annualSalary{};
// Employee's rank (values between 1 & 3)
    int empRank{};
// Dynamic buffer to store company's name
    string *companyName{};
// Dynamic buffer to store department's name
    string *deptName{};
// Operations
public:
// Default constructor & destructor
    Employee();
    Employee(char empName[], unsigned int empId, double annualSalary, int rank);
    ~Employee();
// copy constructor
// copy assignment

    // Methods
    // Set the company name
    void SetCompanyName(char newName[]);

// Set the department name
    void SetDepartmentName(char departmentName[]);

    // Set employee details: name, id, annual salary and rank
    void SetEmployeeDetails(char empName[], unsigned int empId, double
    annualSalary, int rank);

// Get company name
    const string& GetCompanyName();

    // Get department name
    const string& GetDepartmentName();
    // Get employee name
    const string& GetEmployeeName();
// Get employee id
    [[nodiscard]] unsigned int GetEmployeeId() const;

// Get rank and annual salary into the parameters
    void GetRankAndAnnualSalary(int *rank, double *salary) const;
/* Virtual function
Prints out the name of the employee and position */
    virtual void DisplayNameAndPosition();
/* Pure virtual functions of CalculateBonus and
CalculateSalaryIncrement. Details of calculations in Parts (b) and (c).*/
    virtual void CalculateBonus(int *bonusMonths, double *bonusSum) = 0;
    virtual void CalculateSalaryIncrement(double *percentIncrement, double
    *newSalary) = 0;
};
#endif