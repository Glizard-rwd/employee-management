/*
 * This is the implementation file for the Engineer class.
 * This file could be considered as "implementation" of the class.
 * overriding virtual function
 * calculate bonus: find the bonus month => calculate actual bonus amount =>
 */

#include "Engineer.h" // include the Engineer header file
// constructor
Engineer::Engineer() = default;
Engineer::Engineer(char *empName, unsigned int empId, double annualSalary, int rank) : Employee(empName, empId, annualSalary, rank) {}
Engineer::~Engineer() = default;

void Engineer::DisplayNameAndPosition() {
    cout << "Engineer: " << this->GetEmployeeName() << endl;
    cout << "Position: Engineer" << endl;
    cout << "Department: " << this->GetDepartmentName() << endl;
    cout << "Company: " << this->GetCompanyName() << endl;
    cout << "Engineer ID: " << this->GetEmployeeId() << endl;

}

void Engineer::CalculateBonus(int *bonusMonths, double *bonusSum) {
    int engRank;
    double annualSa;
    this->GetRankAndAnnualSalary(&engRank, &annualSa);

    switch(engRank) {
        case 1:
            *bonusMonths = 3;
            break;
        case 2:
            *bonusMonths = 6;
            break;
        case 3:
            *bonusMonths = 9;
            break;
        default:
            *bonusMonths = 0;

    }

    double bonusAmount = *bonusMonths * (annualSa / 12);
    double actualBonus = bonusAmount - ((bonusAmount * INCOME_TAX_PERCENT)/100);
    *bonusSum = actualBonus;

    cout << "Number of bonus months: " << *bonusMonths << endl;
    cout << "Bonus amount: " << *bonusSum << endl;

}

void Engineer::CalculateSalaryIncrement(double *percentIncrement, double *newSalary) {
    int engRank;
    double annualSa;
    this->GetRankAndAnnualSalary(&engRank, &annualSa);

    switch(engRank) {
        case 1:
            *percentIncrement = 4.5;
            break;
        case 2:
            *percentIncrement = 5.5;
            break;
        case 3:
            *percentIncrement = 6.5;
            break;
        default:
            *percentIncrement = 0.0;
    }

    *newSalary = annualSa + (*percentIncrement * annualSa / 100);
    cout << "Salary increment: " << *percentIncrement << endl;
    cout << "New salary: " << *newSalary << endl;
}

