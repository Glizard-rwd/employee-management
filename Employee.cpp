/*
 * This is the implementation file for the Employee class.
 * This file could be considered as "implementation" of the class.
 */
#include "Employee.h" // include the Employee header file

// constructor
Employee::Employee() = default;

// parameterized constructor
Employee::Employee(char *empName, unsigned int empId, double annualSalary, int rank) {
    delete this->empName;
    this->empName = new string(empName);
    this->empId = empId;
    this->annualSalary = annualSalary;
    this->empRank = rank;
}
// destructor
Employee::~Employee() = default;
// set company name
void Employee::SetCompanyName(char newName[]) {
    delete this->companyName;
    this->companyName = new string(newName);
}


// set department name
void Employee::SetDepartmentName(char departmentName[]) {
    delete this->deptName;
    this->deptName = new string(departmentName);

}

// set employee details
void Employee::SetEmployeeDetails(char *empName, unsigned int empId, double annualSalary, int rank) {
    delete this->empName;
    this->empName = new string(empName);
    this->empId = empId;
    this->annualSalary = annualSalary;
    this->empRank = rank;
}

// get company name
const string& Employee::GetCompanyName() {
    if (this->companyName == nullptr) {
        static const string emptyString;
        return emptyString;
    } else {
        return *this->companyName;
    }
}

// get department name
const string& Employee::GetDepartmentName() {
    if (this->deptName == nullptr) {
        static const string emptyString;
        return emptyString;
    } else {
        return *this->deptName;
    }
}
// get employee name
const string& Employee::GetEmployeeName() {
    if (this->empName == nullptr) {
        static const string emptyString;
        return emptyString;
    } else {
        return *this->empName;
    }
}
// get employee empID
unsigned int Employee::GetEmployeeId() const {
    return this->empId;
}

// get rank and annual salary
void Employee::GetRankAndAnnualSalary(int *rank, double *salary) const {
    *rank = this->empRank;
    *salary = this->annualSalary;
}

// virtual function

void Employee::DisplayNameAndPosition() {
    if (this->empName == nullptr) {
        this->empName = new string("Unknown");
    } else {
        cout << "Employee: " << *this->empName << endl;
    }
}
void Employee::CalculateBonus(int *bonusMonths, double *bonusSum) {
// virtual function in based class
}

void Employee::CalculateSalaryIncrement(double *percentIncrement, double
*newSalary) {
// virtual function in based class
}





