#include "Course.hpp"
using namespace std;

Course::Course() {
    this->name = "PLACEHOLDER_COURSE";
    this->location = "PLACEHOLDER_LOCATION";
}

Course::Course(string name_, string location_): name{name_}, location{location_} { };

string Course::getName() const {
    return this->name;
}

string Course::getLocation() const {
    return this->location;
}
Course::~Course() {
    
    // cout << "Course destructor called" << this->name << endl;

    this->name = "X";
    this->location = "Y";
    
}
Course::Course(const Course& obj) {
    //  cout << "Course copy called" << this->name << endl;

    this->name = obj.getName();
    this->location = obj.getLocation();
}

Course& Course::operator=(const Course& obj) {
        //  cout << "Course = called" << this->name << endl;

    this->name = obj.getName();
    this->location = obj.getLocation();
    return *this;
}

ostream& operator<<(ostream& outStream, const Course& co) {
    outStream << co.getName() << "-" << co.getLocation(); 
    return outStream;
}
