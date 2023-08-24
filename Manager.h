#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
class Manager : public Employee{
    // Operations
public:
    Manager();
    Manager(char *empName, unsigned int empId, double annualSalary, int rank); // parameterized constructor
    ~Manager();
    void DisplayNameAndPosition() override;
    void CalculateBonus(int *bonusMonths, double *bonusSum) override;
    void CalculateSalaryIncrement(double *percentIncrement, double
    *newSalary) override;
};
#endif