#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>

using namespace std;

struct Course {

    protected: 
        string name;
        string location;
    
    public:
        Course();
        Course(string name_ = "PLACEHOLDER_COURSE", string location_ = "PLACEHOLDER_LOCATION");
        ~Course();
        Course(const Course &obj);
        Course& operator= (const Course&);
        string getName() const;
        string getLocation() const;
        friend ostream& operator<<(ostream& outStream, const Course& co);
};

#endif