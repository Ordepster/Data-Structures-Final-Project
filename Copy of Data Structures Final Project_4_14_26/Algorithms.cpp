#include "Algorithms.h"

// Merge helper
void merge(vector<Student>& arr, int left, int mid, int right) {
    vector<Student> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i].getId() < arr[j].getId())
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeByGPA(vector<Student>& arr, int left, int mid, int right) {
    vector<Student> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i].getGPA() > arr[j].getGPA()) // descending order
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

// Merge Sort
void mergeSort(vector<Student>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSortByGPA(vector<Student>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortByGPA(arr, left, mid);
    mergeSortByGPA(arr, mid + 1, right);
    mergeByGPA(arr, left, mid, right);
}

// Binary Search
Student* binarySearch(vector<Student>& arr, int targetId) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].getId() == targetId)
            return &arr[mid];
        else if (arr[mid].getId() < targetId)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return nullptr;
}