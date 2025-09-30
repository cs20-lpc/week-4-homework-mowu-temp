// TODO:  Student class methods implementation here.

#include "Student.hpp"

using namespace std;

Student::Student()
{
    this->enrolled = new vector<Course>();
}

Student::Student(const string &id_, const string &name_, const string &gpa_)
{
    this->id = id_;
    this->name = name_;
    this->gpa = gpa_;
    this->enrolled = new vector<Course>();
    // for (Course c : enrolled_) {
    //     this->enrolled->push_back(c);
    // }
}

Student::~Student()
{

    // cout << "Student destructor" << this->id << endl;
    this->id = "X";
    this->name = "Y";
    this->gpa = "Z";

    delete enrolled;
}

Student::Student(const Student &other)
{
    cout << "Student copy" << endl;

    this->id = other.id;
    this->name = other.name;
    this->gpa = other.gpa;

    this->enrolled = new vector<Course> (*other.enrolled);
    for (Course c : *(this->enrolled)) {
        cout << c << endl;
    }
    // vector<Course> cpy = * (new vector<Course>(* other.enrolled));
    // this->enrolled = &cpy;
}
Student &Student::operator=(const Student &other)
{
    // cout << "Student equal operator" << endl;
    this->id = other.id;
    this->name = other.name;
    this->gpa = other.gpa;
    this->enrolled = new vector<Course> (*other.enrolled);
    return *this;
}

string Student::getId() const
{
    return this->id;
}

void Student::addCourse(const string &name, const string &location)
{
    Course c = Course(name, location);
    this->enrolled->push_back(c);
    cout << *this << endl;
}

bool Student::operator==(const Student &other)
{
    return this->id == other.id;
}

ostream &operator<<(ostream &outStream, const Student &stu)
{
    outStream << "Student " << stu.id << ": ";
    outStream << "Name:" << stu.name << ", ";
    outStream << "GPA:" << stu.gpa << ", ";
    outStream << "Courses: " << stu.enrolled->size() << "[";
    for (unsigned long i = 0; i < stu.enrolled->size(); i++)
    {
        Course c = (*(stu.enrolled))[i];
        outStream << c.getName() << " " << c.getLocation();
        if (i + 1 < stu.enrolled->size())
        {
            outStream << ", ";
        }
    }
    outStream << "]";

    return outStream;
}