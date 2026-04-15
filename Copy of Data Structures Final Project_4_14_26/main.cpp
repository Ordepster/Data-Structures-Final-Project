#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Algorithms.h"

using namespace std;

// Add student with duplicate ID check
void addStudent(vector<Student>& students) {
    string name;
    int id;
    double gpa;

    cout << "Enter name: ";
    cin.ignore(); // clears leftover newline
    getline(cin,name);

    cout << "Enter ID: ";
    cin >> id;

    // Check duplicate ID
    for (Student& s : students) {
        if (s.getId() == id) {
            cout << "Duplicate ID not allowed.\n";
            return;
        }
    }

    cout << "Enter GPA: ";
    cin >> gpa;

    students.push_back(Student(name, id, gpa));
    cout << "Student added successfully.\n";
}

// Display all students
void displayStudents(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    for (Student& s : students) {
        s.display();
    }
}

// Delete student
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

//Update student
void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    int id;
    cout << "Enter ID of student to update: ";
    cin >> id;

    for (Student& s : students) {
        if (s.getId() == id) {
            cout << "Student found:\n";
            s.display();

            int choice;
            cout << "\nWhat would you like to update?\n";
            cout << "1. Name\n";
            cout << "2. GPA\n";
            cout << "3. Both\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1 || choice == 3) {
                string newName;
                cout << "Enter new full name: ";
                cin.ignore();
                getline(cin, newName);
                s.setName(newName);
            }

            if (choice == 2 || choice == 3) {
                double newGPA;
                cout << "Enter new GPA: ";
                cin >> newGPA;
                s.setGPA(newGPA);
            }

            cout << "Student updated successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void saveToFile(vector<Student>& students) {
    ofstream file("students.txt");

    for (Student& s : students) {
        file << s.getName() << "," 
             << s.getId() << "," 
             << s.getGPA() << endl;
    }

    file.close();
}

void loadFromFile(vector<Student>& students) {
    students.clear();
	ifstream file("students.txt");

    string name;
    int id;
    double gpa;

    while (getline(file, name, ',')) {
        file >> id;
        file.ignore(); 
        file >> gpa;
        file.ignore();

        students.push_back(Student(name, id, gpa));
    }

    file.close();
}

int main() {
    vector<Student> students;
    loadFromFile(students);
	int choice;

    do {
        cout << "\n===== Student Record System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Sort by ID\n";
        cout << "4. Search by ID\n";
        cout << "5. Delete Student\n";
		cout << "6. Sort by GPA\n";
		cout << "7. Update Student\n";
		cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                if (!students.empty()) {
                    mergeSort(students, 0, students.size() - 1);
                    cout << "Students sorted by ID.\n";
                } else {
                    cout << "No students to sort.\n";
                }
                break;

            case 4: {
                if (students.empty()) {
                    cout << "No students available.\n";
                    break;
                }

                int id;
                cout << "Enter ID to search: ";
                cin >> id;

                Student* result = binarySearch(students, id);

                if (result)
                    result->display();
                else
                    cout << "Student not found.\n";

                break;
            }

            case 5:
                deleteStudent(students);
                break;

            case 6:
    			if (!students.empty()) {
        			mergeSortByGPA(students, 0, students.size() - 1);
        			cout << "Students sorted by GPA (highest to lowest).\n";
    		} else {
        			cout << "No students to sort.\n";
    		}
    			break;

			case 7:
    			updateStudent(students);
    			break;

			case 8:
				saveToFile(students);
    			cout << "Exiting...\n";
    			break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}