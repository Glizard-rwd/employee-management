#include <iostream>
#include <limits>
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"


using std::cout;
using std::cin;
using std::endl;


//void menu() {
//    cout << "\n---------------------------------\n";
//    cout << "      COMPANY MANAGEMENT SYSTEM\n";
//    cout << "---------------------------------\n";
//    cout << "1. View all employee\n";
//    cout << "2. Add employee\n";
//    cout << "3. Remove employee\n";
//    cout << "4. Exit\n";
//    cout << "---------------------------------\n";
//}

int main() {
    string companyName;
    int empNum;
    // prompt for the company name and number of employee
    cout << "Enter the company name: ";
    std::getline(cin >> std::ws, companyName);
    cout << "Enter the number of employee: ";
    cin >> empNum;

    // initialize the array of employee based on empNum
    Employee *employees[empNum];
    for (int i = 0; i < empNum; i++) {
        // choose employee type
        int empType;
        cout << "Enter the employee type (1 - Engineer, 2 - Manager): ";
        cin >> empType;

        if (empType == 1) {
            employees[i] = new Engineer();
        } else if (empType == 2) {
            employees[i] = new Manager();
        } else {
            cout << "Invalid employee type" << endl;
            return 0;
        }

        char *deptName; // dynamic memory allocation
        char *empName; // dynamic memory allocation
        unsigned int empId;
        double annualSalary;
        int empRank;

        deptName = new char[100];
        empName = new char[100];

        // prompt for the employee details
        cout << "Enter the employee department: " << endl;
        cin.getline(deptName, 255);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // include limit
        cout << "Enter the employee name: " << endl;
        cin.getline(empName, 255);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // include limit

        cout << "Enter the employee id: " << endl;
        cin >> empId;
        cout << "Enter the employee annual salary: " << endl;
        cin >> annualSalary;
        cout << "Enter the employee rank: " << endl;
        cin >> empRank;

        // create the employee
        employees[i]->SetEmployeeDetails(empName, empId, annualSalary, empRank);
    }

    // display the employee details
    cout << "Company name: " << companyName << endl;
    cout << "---------------------------------\n";
    cout << "Number of employee: " << empNum << endl;
    cout << "---------------------------------\n";
    cout << "Employee details: " << endl;
    for (int i = 0; i < empNum; i++) {
        cout << "Employee " << i + 1 << endl;
        employees[i]->DisplayNameAndPosition();

        // Call CalculateBonus and CalculateSalaryIncrement
        int bonusMonths;
        double bonusSum;
        employees[i]->CalculateBonus(&bonusMonths, &bonusSum);

        double percentIncrement;
        double newSalary;
        employees[i]->CalculateSalaryIncrement(&percentIncrement, &newSalary);
        cout << "---------------------------------\n";
    }
    return 0;
}