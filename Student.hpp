// TO DO:  Student class definition  here.
#include <iostream>
#include <vector>

using namespace std;

class Student {
    protected: 
        int id = 0;
        string name = "PLACEHOLDER";
        double gpa = 0.0;
        vector<int> enrolled;

    public:
        Student();
        Student(const int& id, const string& name_, const double& gpa_, const vector<int>& enrolled_);
        Student(const Student& other);
        ~Student();
        bool operator== (const Student& other);
        ostream& operator<<(ostream& outStream, const Student& stu);

};