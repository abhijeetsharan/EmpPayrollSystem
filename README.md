# Employee Payroll System

A C++ console-based Employee Payroll System that allows the user to manage both full-time and part-time employees, calculate their salaries, and maintain a list of employees with essential functionalities like adding, removing, and displaying employee details.

## Features

- **Add Full-Time Employee**: Adds a full-time employee with a monthly salary.
- **Add Part-Time Employee**: Adds a part-time employee with hourly wage and hours worked.
- **Remove Employee**: Removes an employee from the system by ID.
- **Display Employees**: Lists all employees with their details, including salary.

## Classes

### Employee (Abstract Class)
- Base class for representing an employee.
- Contains common attributes like `name` and `id`.
- Declares a pure virtual method `calculateSalary()` to calculate an employee’s salary.

### FullTimeEmployee (Derived from Employee)
- Represents full-time employees.
- Contains a monthly salary and overrides the `calculateSalary()` method.

### PartTimeEmployee (Derived from Employee)
- Represents part-time employees.
- Contains attributes for hours worked and hourly rate and overrides the `calculateSalary()` method.

### PayrollSystem
- Manages a list of employees.
- Provides methods to add, remove, and display employees.

## Code Snippet

```cpp
void PayrollSystem::displayEmployees() const {
    for (const auto &employee : employeeList) {
        cout << *employee << endl;
    }
}
