#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(string name, int id);

    virtual void display();
    
    int getId();
    string getName();
};

#endif