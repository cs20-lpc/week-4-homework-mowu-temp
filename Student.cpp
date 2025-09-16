// TODO:  Student class methods implementation here.

#include "Student.hpp"
using namespace std;
Student::Student() {
    enrolled = new vector<int>();
}

Student::Student(const int& id_, const string& name_, const double& gpa_, const vector<int>& enrolled_) {
    this->id = id_;
    this->name = name_;
    this->gpa = gpa_;
    this->enrolled = new vector<int>();
    for (int c : enrolled_) {
        this->enrolled.push_back(c);
    }
}

Student::Student(const Student& other) {
    this->id = other.id;
    this->name = other.name;
    this->gpa = other.gpa;
    this->enrolled = *other.enrolled;
}

Student::~Student() {
    delete enrolled;
}

bool Student::operator==(const Student& other) {
    return this->id == other.id;
}
