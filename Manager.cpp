#include "Manager.h" // include the Manager header file

Manager::Manager() = default;
Manager::Manager(char *empName, unsigned int empId, double annualSalary, int rank) : Employee(empName, empId, annualSalary, rank) {};
Manager::~Manager() = default;
void Manager::DisplayNameAndPosition() {
    cout << "Manager: " << this->GetEmployeeName() << endl;
    cout << "Position: Manager" << endl;
    cout << "Department: " << this->GetDepartmentName() << endl;
    cout << "Company: " << this->GetCompanyName() << endl;
    cout << "Engineer ID: " << this->GetEmployeeId() << endl;
}

void Manager::CalculateBonus(int *bonusMonths, double *bonusSum) {
    int mgRank;
    double annualSa;
    this->GetRankAndAnnualSalary(&mgRank, &annualSa);

    switch(mgRank) {
        case 1:
            *bonusMonths = 2;
            break;
        case 2:
            *bonusMonths = 4;
            break;
        case 3:
            *bonusMonths = 6;
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

void Manager::CalculateSalaryIncrement(double *percentIncrement, double *newSalary) {
    int engRank;
    double annualSa;
    this->GetRankAndAnnualSalary(&engRank, &annualSa);

    switch(engRank) {
        case 1:
            *percentIncrement = 3.5;
            break;
        case 2:
            *percentIncrement = 4.5;
            break;
        case 3:
            *percentIncrement = 5.5;
            break;
        default:
            *percentIncrement = 0.0;
    }

    *newSalary = annualSa + (*percentIncrement * annualSa / 100);
    cout << "Salary increment: " << *percentIncrement << endl;
    cout << "New salary: " << *newSalary << endl;
}

