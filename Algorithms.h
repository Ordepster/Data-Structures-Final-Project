#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "Student.h"

using namespace std;

void mergeSort(vector<Student>& arr, int left, int right);
Student* binarySearch(vector<Student>& arr, int targetId);

#endif
