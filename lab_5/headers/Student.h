#ifndef STUDENT_H
#define STUDENT_H

#include "Pupil.h"

class Student : public Pupil {
   protected:
    int m_course;

    /* data */
   public:
    int getCourse() { return m_course; }
    Student(const string name, const int, const int);
    ~Student();
};

Student::Student(const string name = "Vasya", const int age = 17,
                 const int course = 1)
    : Pupil(name, age), m_course{course} {}

Student::~Student() {}

#endif