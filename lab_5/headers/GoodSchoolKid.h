#ifndef GOODSCHOOLKID_H
#define GOODSCHOOLKID_H

#include "SchoolKid.h"

class GoodSchoolKid : public SchoolKid {
   protected:
    string book;
   public:
    string getBook () { return book; }
    GoodSchoolKid(/* args */);
    ~GoodSchoolKid();
};

GoodSchoolKid::GoodSchoolKid(/* args */) {}

GoodSchoolKid::~GoodSchoolKid() {
    book.clear();
}

#endif