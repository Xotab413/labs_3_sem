#ifndef PUPIL_H
#define PUPIL_H

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Pupil {
   protected:
    string m_name;
    int m_age;

   public:
    Pupil(const string, const int);
    string getName() { return m_name; }
    int getAge() { return m_age; }
    void setName(string name) { m_name = name; }
    void setAge(int age) { m_age = age; }
    friend ostream& operator<<(ostream& out, const Pupil& p);
    virtual ostream& print(ostream& out) const = 0;
    virtual string type() = 0;
    virtual ~Pupil();
};

Pupil::Pupil(const string name = "Ivan", const int age = 6)
    : m_name{name}, m_age{age} {}

Pupil::~Pupil() { m_name.clear(); }

ostream& operator<<(std::ostream& out, const Pupil& p) { return p.print(out); }

#endif