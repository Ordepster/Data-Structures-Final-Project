#include "Student.h"

Student::Student(string name, int id, double gpa)
    : Person(name, id) {
    this->gpa = gpa;
}

double Student::getGPA() {
    return gpa;
}

void Student::display() {
    cout << "Name: " << name
         << ", ID: " << id
         << ", GPA: " << gpa << endl;
}

void Student::setName(string newName) {
    name = newName;
}

void Student::setGPA(double newGPA) {
    gpa = newGPA;
}