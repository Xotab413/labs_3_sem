#ifndef STUDENT_H
#define STUDENT_H

#include "Pupil.h"

class Student : virtual public Pupil {
   protected:
    int m_course;

   public:
    Student(const string name, const int, const int);
    int getCourse() { return m_course; }
    virtual ostream& print(ostream& out) const override;
    ~Student();
};

Student::Student(const string name = "Vasya", const int age = 17,
                 const int course = 1)
    : Pupil(name, age), m_course{course} {}

Student::~Student() {}

ostream& Student::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Course = " << m_course << endl;
    return out;
}

#endif