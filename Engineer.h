/*
 * This is the header file for the Engineer class
 * The Engineer class is derived from the Employee class
 * This file could be considered as "interface" of the class.
 */
#ifndef ENGINEER_H
#define ENGINEER_H
#include "Employee.h"
class Engineer : public Employee{
// Operations
public:
    Engineer();
    Engineer(char *empName, unsigned int empId, double annualSalary, int rank); // parameterized constructor
    ~Engineer();
// Implement Employee virtual functions
    void DisplayNameAndPosition() override;
    // Implement Employee pure virtual functions
    void CalculateBonus(int *bonusMonths, double *bonusSum) override;
    void CalculateSalaryIncrement(double *percentIncrement, double
    *newSalary) override;
};
#endif