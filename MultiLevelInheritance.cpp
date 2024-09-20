#include<iostream>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
public:
    int age;

    // Constructor
    Person(string name = "Unnamed", int age = 0) {
        this->name = name;
        this->age = age;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Method to display Person info
    void displayPersonInfo() const {
        cout << "Person Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class Employee
class Employee : public Person {
protected:
    int employeeID;
    string department;

public:
    // Constructor
    Employee(string name = "Unnamed", int age = 0, int employeeID = 0, string department = "None")
        : Person(name, age) {
        this->employeeID = employeeID;
        this->department = department;
    }

    // Setters
    void setEmployeeID(int id) {
        employeeID = id;
    }

    void setDepartment(string department) {
        this->department = department;
    }

    // Getters
    int getEmployeeID() const {
        return employeeID;
    }

    string getDepartment() const {
        return department;
    }

    // Method to display Employee info
    void displayEmployeeInfo() const {
        cout << "Employee ID: " << employeeID << ", Department: " << department << endl;
        displayPersonInfo(); // Call base class method to show name and age
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    int numOfTeams;

public:
    // Constructor
    Manager(string name = "Unnamed", int age = 0, int employeeID = 0, string department = "None", int numOfTeams = 0)
        : Employee(name, age, employeeID, department) {
        this->numOfTeams = numOfTeams;
    }

    // Setter
    void setNumOfTeams(int num) {
        numOfTeams = num;
    }

    // Getter
    int getNumOfTeams() const {
        return numOfTeams;
    }

    // Method to display Manager info
    void displayManagerInfo() const {
        cout << "Manager is leading " << numOfTeams << " teams." << endl;
        displayEmployeeInfo(); // Call derived class method to show employee and person info
    }
};

// Main function to test the classes
int main() {
    // Creating a Manager object
    Manager m("Alice", 35, 101, "Engineering", 3);

    // Display Manager details
    m.displayManagerInfo();

    return 0;
}
