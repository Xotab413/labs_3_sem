#ifndef SCHOOLKID_H
#define SCHOOLKID_H

#include "Pupil.h"

class SchoolKid: public Pupil {
   protected:
    int m_grade;
   public:
    int getGrade() { return m_grade; }
    SchoolKid(/* args */);
    ~SchoolKid();
};

SchoolKid::SchoolKid(/* args */) {}

SchoolKid::~SchoolKid() {}

#endif