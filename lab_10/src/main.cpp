#include "../headers/List.hpp"
#include "../headers/Exception.hpp"
int main() {
    List<int> list;
    List<double> list_d;
    List<string> list_str;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list_d.push_back(3.2);
    list_d.push_back(2.2);
    list_d.push_back(2.8);

    list_str.push_back("Heelo");
    list_str.push_back("My name");
    list_str.push_back("Semyon");
    try {

    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++) 
        cout << list[i] << " ";
        cout << endl;
    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++) 
        cout << list_d[i] << " ";
        cout << endl;
    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++) 
        cout << list_str[i] << " ";

        cout << endl;

    cout << "Delete first el-ts" << endl;
    list.pop_front();
    list_str.pop_front();
    list_d.pop_front();
    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++) 
        cout << list[i] << " ";
        cout << endl;
    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++) 
        cout << list_d[i] << " ";
        cout << endl;
    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++) 
        cout << list_str[i] << " ";
        cout << endl;

    //----------Find------------------
    cout << "Find in int array " << endl;
    int find_i;
    cin >> find_i;

    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++) 
        if (list[i] == find_i)
            cout << list[i];
        cout << endl;
    cout << "Find in int double " << endl;
    double find_d;
    cin >> find_d;

    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++) 
        if (list_d[i] == find_d)
            cout << list[i];
        cout << endl;
    cout << "Find in string " << endl;
    string find_str;
    cin >> find_str;

    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++) 
        if (list_str[i] == find_str)
            cout << list_str[i];
        cout << endl;
    }
    catch (ListException& ex) {
            system ("clear");
            ex.Nani();
    }

    return 0;
}
// DOP всё в строку 
// Разбиваем её
// поиск подстроки 
// cортировка 