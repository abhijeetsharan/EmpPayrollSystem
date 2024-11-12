// Main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;

    int getId() const { return id; }

    friend ostream &operator<<(ostream &os, const Employee &employee) {
        os << "Employee [name=" << employee.name << ", id=" << employee.id
           << ", salary=" << employee.calculateSalary() << "]";
        return os;
    }
};

class FullTimeEmployee : public Employee {
    double monthlySalary;

public:
    FullTimeEmployee(string name, int id, double salary)
        : Employee(name, id), monthlySalary(salary) {}

    double calculateSalary() const override { return monthlySalary; }
};

class PartTimeEmployee : public Employee {
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string name, int id, int hoursWorked, double hourlyRate)
        : Employee(name, id), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    double calculateSalary() const override { return hoursWorked * hourlyRate; }
};

class PayrollSystem {
    vector<shared_ptr<Employee>> employeeList;

public:
    void addEmployee(shared_ptr<Employee> employee) {
        employeeList.push_back(employee);
    }

    void removeEmployee(int id) {
        auto it = find_if(employeeList.begin(), employeeList.end(),
                          [id](const shared_ptr<Employee> &employee) {
                              return employee->getId() == id;
                          });
        if (it != employeeList.end()) {
            employeeList.erase(it);
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void displayEmployees() const {
        for (const auto &employee : employeeList) {
            cout << *employee << endl;
        }
    }
};

int main() {
    PayrollSystem payrollSystem;
    int choice;
    bool check = true;

    while (check) {
        cout << "\nPayroll System Menu:\n";
        cout << "1. Add Full-Time Employee\n";
        cout << "2. Add Part-Time Employee\n";
        cout << "3. Remove Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int id;
            double salary;
            cout << "\nEnter details for Full Time Employee:-\n";
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Monthly Salary: ";
            cin >> salary;
            payrollSystem.addEmployee(make_shared<FullTimeEmployee>(name, id, salary));
            cout << "\nFull Time Employee added successfully!\n";
            break;
        }
        case 2: {
            string name;
            int id, hours;
            double rate;
            cout << "\nEnter details for Part Time Employee:-\n";
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Hours Worked: ";
            cin >> hours;
            cout << "Enter Hourly Rate: ";
            cin >> rate;
            payrollSystem.addEmployee(make_shared<PartTimeEmployee>(name, id, hours, rate));
            cout << "\nPart Time Employee added successfully!\n";
            break;
        }
        case 3: {
            int idToRemove;
            cout << "Enter Employee ID to Remove: ";
            cin >> idToRemove;
            payrollSystem.removeEmployee(idToRemove);
            break;
        }
        case 4:
            cout << "Employee Details:\n";
            payrollSystem.displayEmployees();
            break;
        case 5:
            cout << "Exiting Payroll System. Goodbye!\n";
            check = false;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
    return 0;
}
