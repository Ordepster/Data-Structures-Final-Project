#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
protected: // can be accessed by Student class
    string name;
    int id;

public:
    Person(string name, int id);

    virtual void display(); //allows overriding in derived classes
    
    //getters
    int getId();
    
	string getName();
};

#endif