// g++ -Wall -Wextra Student.cpp driver.cpp Course.cpp -o driver && ./driver

#include <iostream>
#include <string>
#include "Student.hpp"

#include "LinkedList.hpp"
// #include "Course.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

int main()
{
    



    LinkedList<Student> studentList;
    cout << "┌───────────────────┐" << endl;
    cout << "│ SELECT OPERATION  │" << endl;
    cout << "│ 1. Insert Student │" << endl;
    cout << "│ 2. Delete Student │" << endl;
    cout << "│ 3. Search Student │" << endl;
    cout << "│ 4. Display All    │" << endl;
    cout << "│ 5. Count Students │" << endl;
    cout << "│ 6. Add Course     │" << endl;
    cout << "│ 7. Exit           │" << endl;
    cout << "└───────────────────┘" << endl;

    int choice = -1;
    while (choice != 7) {

        cout << "Enter choice: ";
        string response;
        getline(cin, response);
        choice = -1;
        try {
            choice = stoi(response);
        } catch (std::invalid_argument const& ex) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        if (choice < 1 || choice > 7) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        switch(choice) {
            case 1: {
                cout << "Enter ID: ";
                string id;
                getline(cin, id);
                cout << "Enter Name: ";
                string name;
                getline(cin, name);
                cout << "Enter GPA: ";
                string gpa;
                getline(cin, gpa);
                Student *c = new Student (id, name, gpa);
                studentList.append (*c);
                cout << "here" << endl;
                break;
            }
            case 2: {
                
                break;

            }
            case 3: {
                studentList.simplePrint(cout);
                cout << "Enter ID to search: ";
                string id;
                getline(cin, id);
                function<bool(Student)> f = [id](const Student s) {cout << s << endl; return s.getId() == id;};
                cout << "a"<< endl;
                Student * s = nullptr;
                s = studentList.retrieveElement(f);
                if (s == nullptr) {
                    cout << "ID not found!" << endl;
                } else {
                    cout << "Student " << id << " successfully found" << endl;
                    cout << *s << endl;
                }
                break;
            }
            case 4: {
                if (studentList.getLength() == 0) {
                    cout << "No students in list" << endl;
                } else {
                    cout << "Students in list:" << endl;
                    studentList.simplePrint(cout);
                }
                break;
            }
            case 5: {
                cout << "Total students: " <<  studentList.getLength() << endl;
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                cout << "Goodbye!" << endl;
                break;
            }
        }
        cout << "Loop" << endl;
    }
}
