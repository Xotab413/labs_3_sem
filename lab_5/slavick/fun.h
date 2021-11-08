#ifndef FUNC_H
#define FUNC_H
#include "Professor.h"

int checkNum(); 
string enterStr();
Professor enterOneProfesor();
bool compAge( Professor left, Professor right);
void sortProfrs(std::vector<Professor>& pr_v);
void prntProfesr(const vector<Professor>& professors);
void printMenu();
void prntOther();
vector<Professor> getTempl();
void mainMenu();
#endif