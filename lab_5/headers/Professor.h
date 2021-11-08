#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "GoodSchoolKid.h"
#include "GradeStudent.h"
class Professor : public GradeStudent, public GoodSchoolKid {
   private:
    int m_salary;

   public:
    Professor(const string, const int, const int, const string, const int,
              const string, const int);
    int getSalary() { return m_salary; }
    void setAge(const int age) { m_age = age; }
    void setName(const string name) { m_name = name; }
    void setGrade(const int grade) { m_grade = grade; }
    void setCourse(const int course) { m_course = course; }
    void setBook(const string book) { m_book = book; }
    void setWorkpl(const string workpl) { m_workpl = workpl; }
    void setSalary(const int salary) { m_salary = salary; }

    ostream& print(ostream& out) const override;
    ~Professor();
};

Professor::Professor(const string name = "Bob", const int age = 36,
                     const int grade = 9, const string book = "War&Peace",
                     const int course = 5, const string worlpl = "MIT",
                     const int salary = 4000)
    : Pupil(name, age),
      GoodSchoolKid(name, age, grade, book),
      GradeStudent(name, age, course, worlpl),
      m_salary{salary} {}

Professor::~Professor() {}

ostream& Professor::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl
        << "Course = " << m_course << endl
        << "Favorite book = " << m_book << endl
        << "Workplace = " << m_workpl << endl
        << "Salary = " << m_salary << "$" << endl;
    return out;
}
#endif