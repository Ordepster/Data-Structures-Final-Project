#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    double gpa;

public:
    Student(string name, int id, double gpa);

    double getGPA();

    void display() override;
    
    //Setters
    void setName(string newName);
	void setGPA(double newGPA);
};

#endif