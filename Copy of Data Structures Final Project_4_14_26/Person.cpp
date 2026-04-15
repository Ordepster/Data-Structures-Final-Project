#include "Person.h"

Person::Person(string name, int id) {
    this->name = name;
    this->id = id;
}

void Person::display() {
    cout << "Name: " << name 
		 << ", ID: " << id << endl;
}

//getters
int Person::getId() {
    return id;
}

string Person::getName() {
    return name;
}