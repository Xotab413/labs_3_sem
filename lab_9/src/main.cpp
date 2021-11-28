#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Error{
    string error;
public:
    Error(string _name):error(_name){}
    string getError(){return error;}
};
class Plant
        {
    double lenght =0.0;
    string _name="";
    int age=0;
public:
    Plant(){}
    Plant(double lenght ,string name,int age){this->lenght =lenght ;this->_name=name;this->age=age;}
    Plant(Plant const &x){_name=x._name;age=x.age;lenght =x.lenght ;}
    //Plant operator =(Plant x){_name=x._name;age=x.age;lenght =x.lenght ;}
    void show(){cout<<"Name:"<<_name<<"\nlenght :"<<lenght <<"age:"<<age<<endl;}
    void setlenght (double lenght ){this->lenght =lenght ;}
    void textMode(string name) {
        system("clear");
        bool f = true;
        string s;
        do {
            cout << "1-Enter Plant" << endl
                 << "2-Print Plant" << endl
                 << "3-Rev print Plants" << endl
                 << "4-Find Plant" << endl
                 << "5-Delete Plant" << endl
                 << "0-Exit" << endl;
            int n;
            cin >> n;
            try {
                switch (n) {
                    case 1: {
                        ofstream fout(name, ios::app);
                        if (!fout) {
                            f = false;
                            throw Error("Error (file openning)");
                        }
                        cout << "Enter a name of Plant: ";
                        cin.ignore();
                        cin >> _name;
                        cout << "Enter a age of Plant: ";
                        cin >> age;
                        cout << "Enter a lenght of Plant: ";
                        cin >> lenght ;
                        fout << this->_name << endl << age << endl << lenght  << endl;
                        system("clear");
                        break;
                    }
                    case 2: {
                        ifstream fin(name);
                        if (!fin) {
                            f = false;
                            throw Error("Error open file");
                        }
                        system("clear");
                        while (!fin.eof()) {
                            getline(fin, s);
                            if (s == "") continue;
                            cout << s << endl;
                        }
                        break;
                    }
                    case 3: {
                        ifstream fin(name);
                        char c;
                        if (!fin) {
                            f = false;
                            throw Error("Error open file");
                        }
                        system("clear");
                        fin.seekg(0, fin.end);
                        long long len = fin.tellg();
                        len--;

                        while (len--) {
                            fin.seekg(len, fin.beg);
                            fin.get(c);
                            if (c != '\n' && len != 0)
                                continue;
                            if (len == 0) {
                                fin.seekg(len, fin.beg);
                                getline(fin, s);
                                if (s == "") break;
                                cout << s << endl;
                                break;
                            } else {
                                fin.seekg(len + 1, fin.beg);
                                getline(fin, s);
                                if (s == "") continue;
                                cout << s << endl;
                            }
                        }
                        break;
                    }
                    case 4: {
                        ifstream fin(name);
                        if (!fin) {
                            f = false;
                            throw Error("Error open file");
                        }
                        system("clear");
                        int l = 0;
                        string find, cheak;
                        cout << "Enter the name for search: ";
                        cin.ignore();
                        getline(cin, find);
                        while (!fin.eof()) {
                            getline(fin, cheak);
                            if (cheak == find) {
                                l++;
                                cout << cheak << endl;
                                getline(fin, cheak);
                                cout << cheak << endl;
                                getline(fin, cheak);
                                cout << cheak << endl;
                            } else {
                                getline(fin, cheak);
                                getline(fin, cheak);
                            }
                        }
                        if (l == 0) {
                            system("clear");
                            cout << "Not found!" << endl;
                        }
                        break;
                    }
                    case 5: {
                        ifstream fin(name);
                        if (!fin) {
                            f = false;
                            throw Error("Error open file");
                        }
                        system("clear");
                        string find, buf;
                        vector<string> arr;
                        cout << "What Plant must be deleted?: ";
                        cin.ignore();
                        getline(cin, find);
                        while (!fin.eof()) {
                            buf = "";
                            getline(fin, buf);
                            if (buf == find) {
                                getline(fin, buf);
                                getline(fin, buf);
                                continue;
                            }
                            arr.push_back(buf);
                        }
                        fin.close();
                        ofstream fout(name);
                        for (string check: arr) fout << check << endl;
                        fout.close();
                        break;
                    }
                    case 0:
                        f = false;
                        break;
                    default:
                        throw Error("False input!");
                        break;
                }
            } catch (Error &e) {
                system("clear");
                cout << e.getError() << endl;
            }

        } while (f);
    }
    void binaryMode(string name){
        system("clear");
        int n;
        bool f = true;
        string s;
        do{
            cout <<endl
                 << "1-Enter Plant" << endl
                 << "2-Print Plants" << endl
                 << "3-Rev print" << endl
                 << "4-Find Plant" << endl
                 << "5-Delete Plant" << endl
                 << "0-Exit" << endl;
            cin >> n;
            try {
                switch (n) {
                    case 1:{
                        ofstream fout(name, ios::app | ios::binary | ios::in);
                        if (!fout){
                            f = false;
                            throw Error("Error can't open file");
                        }
                        cout << "Enter a name of Plant: ";
                           cin.ignore();
                           cin >> _name;
                           cout << "Enter a age of Plant: ";
                           cin >> age;
                           cout << "Enter a average lenght  of Plant: ";
                           cin >> lenght ;
                        fout.write((char*)&this->_name, sizeof(this->_name));
                        fout.write((char*)&age, sizeof(age));
                        fout.write((char*)&lenght , sizeof(lenght ));
                        system("clear");
                        fout.close();
                        break;
                    }
                    case 2:{
                        ifstream fin(name, ios::binary| ios::out);
                        if (!fin){
                            f = false;
                            throw Error("Error opening file!");
                        }
                        system("clear");
                        fin.seekg(0, fin.end);
                        long long l = fin.tellg();
                        fin.seekg(0, fin.beg);
                        while (l) {
                            l-=sizeof(this->_name)+sizeof(age)+sizeof(lenght );
                            fin.read((char*)&this->_name, sizeof(this->_name));
                            fin.read((char*)&age, sizeof(age));
                            fin.read((char*)&lenght , sizeof(lenght ));
                            cout << this->_name << endl << age << endl << lenght  << endl;
                        }
                        fin.close();
                        break;
                    }
                    case 3:{
                        ifstream fin(name, ios::binary|ios::out);
                        char c;
                        if (!fin){
                            f = false;
                            throw Error("Error opening file!");
                        }
                        system("clear");
                        fin.seekg(0, fin.end);
                     long long len = fin.tellg(), k = 0;

                     while (len) {
                         len-=sizeof(this->_name)+sizeof(age)+sizeof(lenght );
                         if(k == 0) fin.seekg(-(int)sizeof(lenght ), fin.cur);
                         else fin.seekg(-(int)(sizeof(lenght )+sizeof(this->_name)), fin.cur);
                         fin.read((char*)&lenght , sizeof(lenght ));
                         fin.seekg(-(int)(sizeof(age)+sizeof(lenght )), fin.cur);
                         fin.read((char*)&age, sizeof(age));
                         fin.seekg(-(int)(sizeof(this->_name)+sizeof(age)), fin.cur);
                         fin.read((char*)&this->_name, sizeof(this->_name));

                         cout << lenght  << endl << age << endl << _name << endl;
                         k++;
                        }
                     fin.close();
                        break;
                    }
                    case 4:{
                        ifstream fin(name, ios::binary| ios::out);
                        if (!fin){
                            f = false;
                            throw Error("Error opening file");
                        }
                        system("clear");
                        int l = 0;
                        string find;
                        cout << "Enter the name of Plant: ";
                        cin.ignore();
                        getline(cin, find);
                        fin.seekg(0, fin.end);
                        long long h = fin.tellg();
                        fin.seekg(0, fin.beg);
                        while(h){
                            h-=sizeof(this->_name)+sizeof(age)+sizeof(lenght );
                            fin.read((char*)&this->_name, sizeof(this->_name));
                            if(this->_name == find){
                                l++;
                                cout << this->_name << endl;
                                fin.read((char*)&age, sizeof(age));
                                cout << age << endl;
                                fin.read((char*)&lenght , sizeof(lenght ));
                                cout << lenght  << endl;
                            }
                            else
                                fin.seekg((sizeof(age)+sizeof(lenght )), fin.cur);
//
                        }
                        if(l == 0){
                            system("clear");
                            cout << "Not found!" << endl;
                        }
                        fin.close();
                        break;
                    }
                    case 5:{
                        ifstream fin(name, ios::binary);
                        if (!fin){
                            f = false;
                            throw Error("Error opening file");
                        }

                        system("clear");
                        int l = 3, ll = 0;
                        string *mass, *mass1;
                        string find, cheak;
                        cout << "What Plant must be deleted: ";
                        cin.ignore();
                        getline(cin, find);
                        fin.seekg(0, fin.end);
                        long long h = fin.tellg();
                        fin.seekg(0, fin.beg);

                        while(h){
                            h-=sizeof(_name)+sizeof(age)+sizeof(lenght );
                            fin.read((char*)&_name, sizeof(_name));
                            fin.read((char*)&age, sizeof(age));
                            fin.read((char*)&lenght , sizeof(lenght ));

                            mass = new string[l];

                            for(int i = 0; i < ll; i++)
                                mass[i] = mass1[i];

                            mass[l-3] = _name;
                            mass[l-2] = to_string(age);
                            mass[l-1] = to_string(lenght );

                            mass1 = new string[l];

                            for(int i = 0; i < l; i++)
                                mass1[i] = mass[i];

                            ll = l;
                            l+=3;
                        }
                        for(int i = 0; i < l; i+=3){
                            if(find == mass[i]){
                                cout << mass[i] << endl << mass[i+1] << endl << mass[i+2] << endl;
                                mass[i] = mass[i+1] = mass[i+2] = "";
                                ll-=3;
                            }
                        }
                        fin.close();
                        ofstream fout(name, ios::binary);
                        if (!fout){
                            f = false;
                            throw Error("Error openin file!");
                        }
                        fout.close();
                        if(ll == 0){
                            break;
                        }
                        else{
                            ofstream fout(name, ios::binary);
                            for(int i = 0; i+3 < l; i+=3){
                                if(mass[i] == "") continue;
                                try{
                                    _name = mass[i];
                                    age = stoi(mass[i+1]);
                                    lenght  = stod(mass[i+2]);
                                    fout.write((char*)&_name, sizeof(_name));
                                    fout.write((char*)&age, sizeof(age));
                                    fout.write((char*)&lenght , sizeof(lenght ));
                                }
                                catch(...){
                                    fout.close();
                                }

                            }
                        }
                        break;
                    }
                    case 0:{f = false;
                        break;}
                    default:
                        throw Error("False input!");
                        break;
                }
            } catch (Error &e) {
                system("clear");
                cout << e.getError() << endl;
            }

        }while(f);
    }
        };
int main() {
    Plant buf;
    do{
        int choice;
        cout << "1-Text file in text mode;" << endl
             << "2-Text file in binary mode;" << endl
             << "3-Binary file in binary mode;" << endl
             << "0-Exit;" << endl << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                buf.textMode("../out/TextText.txt");
                break;
            case 2:
                buf.binaryMode("../out/TextBynary.txt");
                break;
            case 3:
                buf.binaryMode("../out/Bynary.dat");
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"False input!";
        }
    }while(true);
    return 0;
}