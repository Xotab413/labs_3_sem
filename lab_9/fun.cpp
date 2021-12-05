#include "../headers/fun.h"

#include "../headers/FileException.h"
#include "../headers/Plant.h"

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
void printMenu() {
    cout << endl
         << "1 - Enter Plant" << endl
         << "2 - Print Plants" << endl
         << "3 - Rev print" << endl
         << "4 - Find Plant" << endl
         << "5 - Delete Plant" << endl
         << "6 - Delete Duplicate" << endl
         << "7 - Sort Plants" << endl
         << "8 - Find Diapazone" <<endl
         << "0 - Exit" << endl;
}


void printFileType() {
    cout << "1 - Text file in text mode;" << endl
         << "2 - Text file in binary mode;" << endl
         << "3 - Binary file in binary mode;" << endl
         << "Other num - Exit;" << endl;
}

void mainMenu() {
    Plant some;
    while (1) {
        system("clear");
        printFileType();
        try {
            int chooser{checkNum()};
            switch (chooser) {
                case 1:
                    some.textMode("../out/text_in_text.txt");
                    break;
                case 2:
                    some.binaryMode("../out/text_in_binary.dat");
                    break;
                case 3:
                    some.binaryMode("../out/binary_in_binary.dat");
                    break;
                default:
                    return;
            }
        } catch (FileException &ex) {
            system("clear");
            ex.Nani();
        }
    }
}
