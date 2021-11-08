#ifndef SCHOOLKID_H
#define SCHOOLKID_H

#include "Pupil.h"

class SchoolKid : virtual public Pupil {
   protected:
    int m_grade;

   public:
    SchoolKid(const string, const int, const int);
    int getGrade() { return m_grade; }
    virtual ostream& print(ostream& out) const override;
    ~SchoolKid();
};

SchoolKid::SchoolKid(const string name = "Petya", const int age = 10,
                     const int grade = 3)
    : Pupil(name, age), m_grade{grade} {}

SchoolKid::~SchoolKid() {}

ostream& SchoolKid::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl;
    return out;
}
#endif