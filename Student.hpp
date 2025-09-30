#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>

#include "Course.hpp"

using namespace std;

class Student {
    protected: 
        string id = "0";
        string name = "PLACEHOLDER";
        string gpa = "0.0";
        vector<Course>* enrolled;

    public:
        Student();
        Student(const string&, const string&, const string&);
        ~Student();
        Student(const Student&);
        Student& operator=(const Student&);

        string getId() const;
        void addCourse(const string&, const string&);

        bool operator== (const Student&);
        friend ostream& operator<<(ostream&, const Student&);

};

#endif