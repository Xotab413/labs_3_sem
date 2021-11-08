#ifndef FUNC_H
#define FUNC_H
#include "GradeStudent.h"
#include "SchoolKid.h"



GradeStudent enterOneGradeStudent() {
    GradeStudent grdS;
    cout << "Enter a Name: ";
    grdS.setName(enterStr());
    cout << "Enter a Age: ";
    grdS.setAge(checkNum());
    cout << "Enter a Course: ";
    grdS.setCourse(checkNum());
    cout << "Enter a Workplace ";
    grdS.setWorkpl(enterStr());

    return grdS;
}
Student enterOneStudent() {
    Student stdnt;
    cout << "Enter a Name: ";
    stdnt.setName(enterStr());
    cout << "Enter a Age: ";
    stdnt.setAge(checkNum());
    cout << "Enter a Course: ";
    stdnt.setCourse(checkNum());

    return stdnt;
}
SchoolKid enterOneSchoolKid() {

    SchoolKid schk;
    cout << "Enter a Name: ";
    schk.setName(enterStr());
    cout << "Enter a Age: ";
    schk.setAge(checkNum());
    cout << "Enter a Grade: ";
    schk.setGrade(checkNum());

    return schk;
    
}




void menuCreation() {
    cout << "Press : " << endl 
         << "1 - for Student" << endl
         << "2 - for SchoolKid" <<endl
         << "3 - for GradeStudent" << endl
         << endl;

}

void createPupils (Pupil** &mas, const int & size) {

    for (int i = 0; i < size; i++) {
        while(1) {
            switch(checkNum()) {
                case 1:
                    mas[i] = new enterOneStudent();
            }
        }
    }
    
}


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
void prntPupils(Pupil*  arr, const int size) {
    int i{1};
    system("clear");
    if (!size) {
        cout << "Create at least one Pupil" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Position - " << i++ << endl
             << "--------------------------------" << endl
             << "Hello use i'm a " << arr[i].type() << endl
             << arr[i] 
             << "--------------------------------" << endl;
    }
}
void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - add professor" << endl
         << "2 - print all Pupils" << endl
         << "3 - sort professor" << endl
         << "4 - print other classes" << endl
         << "5 - use Template for Professor" << endl
         << "Oher num - exit" << endl
         << endl;
}



// vector<Professor> getTempl() {
//     vector<Professor> tmpl{
//         Professor("Charlie", 54, 10, "Tim&Taller", 3, "BSU", 500),
//         Professor("Josh", 36, 9, "The Great Gatsby", 2, "Oxford", 3400),
//         Professor("Martin", 84, 11, "Moby Dick", 1, "BSUIR", 1000),
//         Professor("Kirill", 45, 9, "Hamlet", 5, "Oxford", 2000),
//         Professor("Nil", 66, 8, "The Trial", 4, "Yale", 3450)};
//     return tmpl;
// }


void mainMenu() {
    Pupil** ppl;
    int size {0};
    printMenu();
    while (1) {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:
                cout << "Please enter a size of arr" << endl;
                size = checkNum();
                ppl = new Pupil* [size];
                createPupils
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