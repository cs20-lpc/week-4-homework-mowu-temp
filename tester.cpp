/*
g++ -Wall -Wextra Student.cpp tester.cpp Course.cpp -o tester && ./tester
*/

#include <iostream>
#include <string>
#include "Student.hpp"
#include "LinkedList.hpp"

int main()
{
    // Student *s = new Student("ida", "namea", "gpaa");
    // Student v = *s;
    // // v = s;
    
    // cout << "[s] "  << *s << endl;

    // cout << "[v] " << v << endl;
    // delete s;
    LinkedList<Student> myList;
    // cout << "12" << endl;
    Student s1 = Student("a", "a", "a");
    s1.addCourse("CS101", "location");
    myList.append(s1);
    // myList.append(Student("b", "b", "b"));
    // myList.append(Student("c", "c", "c"));
    // myList.append(Student("d", "d", "d"));
    Student s = myList.getElement(0);
    s.addCourse("CS101", "location");
    myList.simplePrint(cout);
    // myList.simplePrint(cout);
    // myList.simplePrint(cout);



    // Student s = Student( "a", "b", "c");
    // cout << s << endl;
    // Student v = s;
    // cout << v << endl;
    // cout << v.getId()<< endl;

}