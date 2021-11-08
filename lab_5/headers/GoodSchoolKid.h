#ifndef GOODSCHOOLKID_H
#define GOODSCHOOLKID_H

#include "SchoolKid.h"

class GoodSchoolKid : public SchoolKid {
   protected:
    string m_book;

   public:
    GoodSchoolKid(const string, const int, const int, const string book);
    string getBook() { return m_book; }
    ostream& print(ostream& out) const override;
    ~GoodSchoolKid();
};

GoodSchoolKid::GoodSchoolKid(const string name = "Oleg", const int age = 14,
                             const int grade = 5,
                             const string book = "Harry Potter")
    : Pupil(name, age), SchoolKid(name, age, grade), m_book(book) {}

GoodSchoolKid::~GoodSchoolKid() { m_book.clear(); }

ostream& GoodSchoolKid::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl
        << "Favorite book = " << m_book << endl;
    return out;
}

#endif