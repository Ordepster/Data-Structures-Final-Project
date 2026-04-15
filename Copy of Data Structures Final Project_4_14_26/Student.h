#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person { //Inheritance from Person
private:
    double gpa;

public:
    Student(string name, int id, double gpa);

	//getter
    double getGPA();

    void display() override;
    
    //Setters
    void setName(string newName);
	void setGPA(double newGPA);
};

#endif