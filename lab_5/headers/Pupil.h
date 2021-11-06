#ifndef PUPIL_H
#define PUPIL_H

#include <iostream>
using namespace std;
class Pupil {
   protected:
    string m_name;
    int m_age;

   public:
    string getName() { return m_name; }
    int getAge() { return m_age; }
    Pupil(const string, const int);
    ~Pupil();
};

Pupil::Pupil(const string name = "Ivan", const int age = 6)
    : m_name{name}, m_age{age} {}

Pupil::~Pupil() { m_name.clear(); }

#endif