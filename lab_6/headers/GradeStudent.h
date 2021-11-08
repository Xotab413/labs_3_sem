#ifndef GRADESTUDENT_H
#define GRADESTUDENT_H

#include "Student.h"

class GradeStudent : public Student {
   protected:
    string m_workpl;

   public:
    GradeStudent(const string, const int, const int, const string);
    string getWorkpl() { return m_workpl; }
    void setWorkpl(string workpl) { m_workpl = workpl;}
    string type() override { return "GradeStudent";}
    ostream& print(ostream& out) const override;
    ~GradeStudent();
};

GradeStudent::GradeStudent(const string name = "George", const int age = 23,
                           const int course = 4,
                           const string workplc = "Google")
    : Pupil(name, age), Student(name, age, course), m_workpl{workplc} {}

GradeStudent::~GradeStudent() {}

ostream& GradeStudent::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Course = " << m_course << endl
        << "Workplace = " << m_workpl << endl;
    return out;
}

#endif