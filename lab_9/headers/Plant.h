#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Plant {
    double m_lenght;
    string m_name;
    int m_age;

   public:
    Plant() {
        m_lenght = 0.0;
        m_name = "";
        m_age = 0;
    }
    Plant(double, string, int);
    Plant(Plant const &plant);
    friend ostream& operator<<(ostream& os, const Plant& plant);
    friend istream& operator>>(istream& is, Plant& plant);
    void textMode(const string);
    void binaryMode(const  string);
};

#endif