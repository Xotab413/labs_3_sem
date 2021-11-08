#ifndef FUNC_H
#define FUNC_H
#include "Professor.h"

int checkNum() {
    int num{0};
    while (true) {
        if (cin >> num)
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): " << endl;
        }
    }
    return num;
}
string enterStr() {
    string some{};
    cin >> some;
    return some;
}
Professor enterOneProfesor() {
    Professor prf;
    cout << "Enter a Name: ";
    prf.setName(enterStr());
    cout << "Enter a Age: ";
    prf.setAge(checkNum());
    cout << "Enter a Grade ";
    prf.setGrade(checkNum());
    cout << "Enter a Course ";
    prf.setCourse(checkNum());
    cout << "Enter a Favorite book ";
    prf.setBook(enterStr());
    cout << "Enter a Workplace ";
    prf.setWorkpl(enterStr());
    cout << "Enter a Salary ";
    prf.setSalary(checkNum());

    return prf;
}
bool compAge( Professor left, Professor right) {
    return left.getAge() < right.getAge(); 
}
void sortProfrs(std::vector<Professor>& pr_v) {
    system("clear");
    if (pr_v.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    std::sort(pr_v.begin(),pr_v.end(),compAge); // by ages
}
void prntProfesr(const vector<Professor>& professors) {
    int i{1};
    system("clear");
    if (professors.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    for (auto& profesor : professors) {
        cout << "Position - " << i++ << endl
             << "--------------------------------" << endl
             << profesor << endl
             << "--------------------------------" << endl;
    }
}
void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - add professor" << endl
         << "2 - print all professors" << endl
         << "3 - sort professor" << endl
         << "4 - print other classes" << endl
         << "5 - use Template for Professor" << endl
         << "Oher num - exit" << endl
         << endl;
}
void prntOther() {

    system("clear");
    GoodSchoolKid gSchKid;
    GradeStudent grS;
    Pupil pupil;
    SchoolKid schoolKid;
    Student student;

    cout << "Hi i'm Pupil " << endl
         << pupil << endl
         << "Hi i'm GoodSchoolKid " << endl
         << gSchKid << endl
         << "Hi i'm GradeStudent " << endl
         << grS << endl
         << "HI i'm just schoolKid " << endl
         << schoolKid << endl
         << "Hi dude i'm StuDent " << endl
         << student << endl;
}
vector<Professor> getTempl() {
    vector<Professor> tmpl{
        Professor("Charlie", 54, 10, "Tim&Taller", 3, "BSU", 500),
        Professor("Josh", 36, 9, "The Great Gatsby", 2, "Oxford", 3400),
        Professor("Martin", 84, 11, "Moby Dick", 1, "BSUIR", 1000),
        Professor("Kirill", 45, 9, "Hamlet", 5, "Oxford", 2000),
        Professor("Nil", 66, 8, "The Trial", 4, "Yale", 3450)};
    return tmpl;
}
void mainMenu() {
    vector<Professor> prf_v;
    printMenu();
    while (1) {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:
                prf_v.push_back(enterOneProfesor());
                system("clear");
                printMenu();
                break;
            case 2:
                prntProfesr(prf_v);
                printMenu();
                break;
            case 3:
                sortProfrs(prf_v);
                printMenu();
                break;
            case 4:
                prntOther();
                printMenu();
                break;
            case 5:
                prf_v.clear();
                prf_v = getTempl();
                system("clear");
                printMenu();
                break;
            default:
                return;
        }
    }
}

#endif