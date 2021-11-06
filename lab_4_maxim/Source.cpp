#include<iostream>
#include<complex>
#include<Windows.h>
#include<new>
#include "Comp.cpp"
using namespace std;
class Array {
	Compl* mas;
	int size;
public:
	Array() { // два массива с компл числами 1 сорт от больш к меньш и выводим в пределах 2  по убыв и целая часть
		size = 0;
		mas = nullptr;
	}
	Array(int n) {
		size = n;

		mas = new Compl[n];
		for (int i = 0; i < n; i++) {
			mas[i].input();
		}
	}
	Array(Array& other) {
		size = other.size;
		mas = new Compl[other.size];
		for (int i = 0; i < size; i++) {
			mas[i] = other.mas[i];
		}
	}
	~Array() {
		delete[]mas;
	}
	Array& operator=(Array& other) {
		if (this != &other) {
			delete[]mas;
			mas = new Compl[other.size];
			size = other.size;
			for (int i = 0; i < size; i++) {
				mas[i] = other.mas[i];
			}
		}
		return *this;
	}
	Compl& get_mas(int i) {
		return mas[i];
	}
	int& get_size() {
		return size;
	}
	void show_all() {
		for (int i = 0; i < size; i++) {
			mas[i].show();
			cout << endl;
		}
		cout << endl;
	}
	void sort(int x1,int x2, int type) {
		Compl a;
		if (type == 1) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (double(mas[i]) > double(mas[j])) {
						a = mas[i];
						mas[i] = mas[j];
						mas[j] = a;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				if (mas[i].get_i() > x1 && mas[i].get_i() < x2)
				{
					mas[i].show();
					cout << endl;
				}
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (double(mas[i]) < double(mas[j])) {
						a = mas[i];
						mas[i] = mas[j];
						mas[j] = a;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				if (mas[i].get_c() > x1 && mas[i].get_c() < x2)
				{
					mas[i].show();
					cout << endl;
				}
			}
		}
	}
	void add() {
		size++;
		Compl* mas1 = new Compl[size];
		for (int i = 0; i < size - 1; i++) {
			mas1[i] = mas[i];
		}

		delete[] mas;
		mas = new Compl[size];
		for (int i = 0; i < size - 1; i++) {
			mas[i] = mas1[i];
		}
		delete[]mas1;
		mas[size - 1].input();


	}

	void del(int n) {
		Compl* mas1 = new Compl[size];
		for (int i = 0; i < size; i++) {
			mas1[i] = mas[i];
		}

		delete[] mas;
		mas = new Compl[size - 1];
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (i == n) {
				j--;
				continue;
			}
			mas[j] = mas1[i];
		}
		size--;
		delete[]mas1;
	}
	void* operator new[](size_t tip) {

		Array* tre = (Array*)malloc(tip);

		return tre;
	}

		void operator delete[](void* p) {
		free(p);
	}
};

Array* add(Array* mas, int n) {
	Array* mas1 = new Array[n - 1];
	for (int i = 0; i < n - 1; i++) {
		mas1[i] = mas[i];

	}
	delete[]mas;
	mas = new Array[n];
	for (int i = 0; i < n - 1; i++) {
		mas[i] = mas1[i];
	}
	delete[]mas1;
	int a;
	cout << "Input number of Complex number" << endl;
	cin >> a;
	new(&mas[n - 1]) Array(a);
	return mas;
}
void inp(int& a, int n) {
	if (n != 0) {
		do {
			if (cin.fail()) // если предыдущее извлечение было неудачным,
			{
				cin.clear(); // то возвращаем cin в 'обычный' режим работы
				cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}

			cin >> a;


		} while (a <= 0 || a > n);
	}
	else {
		do {
			if (cin.fail()) // если предыдущее извлечение было неудачным,
			{
				cin.clear(); // то возвращаем cin в 'обычный' режим работы
				cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}

			cin >> a;


		} while (a <= 0);
	}
	a--;

}

Array* new_obj(int n) {

	Array* tre = new Array[n];
	for (int i = 0; i < n; ++i) {
		int a;
		cout << "Input number of Complex number" << endl;
		inp(a, 0);
		a++;

		new(&tre[i]) Array(a);
	}
	return tre;
}
void show_all_obj(Array* mas, int n) {
	for (int i = 0; i < n; i++) {
		mas[i].show_all();
	}

}
void get_i(Array* mas, int n) {
	cout << "Input number of object" << endl;
	int i;
	inp(i, n);
	mas[i].show_all();
	cout << "Input number of Complex number wich you want" << endl;
	int j;
	inp(j, mas[i].get_size());
	system("cls");
	mas[i].get_mas(j).show();
	cout << endl;
}
void get_s(Array* mas, int n) {
	cout << "Input number of object which size you want to know" << endl;
	int i;
	inp(i, n);
	cout << mas[i].get_size();
	cout << endl;
}
void menu() {
	cout << "1:Add new Array object" << endl;
	cout << "2:Show all Complex number of all Arrays" << endl;
	cout << "3:Delete object" << endl;
	cout << "4:Sort object" << endl;
	cout << "5:Show one Complex number" << endl;
	cout << "6:Show size of one Array" << endl;
	cout << "7:Add new Complex number in to Array" << endl;
	cout << "8:Delete one Complex number" << endl;
}
void sorted(Array* mas, int n) {
	cout << "Input type of sort" << endl;
	cout << "1: Imaginary part" << endl;
	cout << "2: Complex part" << endl;
	int type;
	inp(type, 2);
	type++;
	if (type == 1) {
		cout << "Input number of object wich you want to sort" << endl;
		int a;
		inp(a, n);
		cout << "Input limits" << endl;
		int x1, x2;
		inp(x1, 0);
		x1++;
		inp(x2, 0);
		x2++;
		mas[a].sort(x1,x2,type);
	}
	else {
		cout << "Input number of object wich you want to sort" << endl;
		int a;
		inp(a, n);
		cout << "Input limits" << endl;
		int x1, x2;
		inp(x1, 0);
		x1++;
		inp(x2, 0);
		x2++;
		mas[a].sort(x1, x2, type);
	}
	
}
void add_comp(Array* mas, int n) {
	system("cls");
	show_all_obj(mas, n);
	cout << "Input number of object in wich you want add complex number" << endl;
	int a;

	inp(a, n);
	mas[a].add();

}
Array* del(Array* mas, int n) {
	system("cls");
	show_all_obj(mas, n + 1);
	cout << "Input number of object wich you want delete" << endl;
	int d;
	inp(d, n + 1);
	Array* mas1 = new Array[n + 1];
	for (int i = 0; i < n + 1; i++) {
		new(&mas1[i]) Array(mas[i]);

	}
	delete[]mas;
	mas = new Array[n];
	for (int i = 0, j = 0; i < n + 1; i++, j++) {
		if (i == d) {
			j--;
			continue;
		}
		new(&mas[j]) Array(mas1[i]);
	}
	delete[]mas1;

	return mas;

}
void del_compl(Array* mas, int n) {
	system("cls");
	show_all_obj(mas, n);
	cout << "Input number of object in wich you want delete complex number" << endl;
	int a;

	inp(a, n);
	mas[a].show_all();
	cout << "Input number of Complex number wich you want delete" << endl;
	int b;
	inp(b, mas[a].get_size());
	mas[a].del(b);
}
int main() {
	int n;
	cout << "Input number of objects" << endl;
	do {
		if (cin.fail()) // если предыдущее извлечение было неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}

		cin >> n;

	} while (n <= 0);
	Array* mas = new_obj(n);
	while (1) {

		int choice;
		menu();
		cin >> choice;
		switch (choice) {
		case 1: mas = add(mas, ++n); break;
		case 2: system("cls"); show_all_obj(mas, n); break;
		case 3: mas = del(mas, --n); break;
		case 4: sorted(mas, n); break;
		case 5: get_i(mas, n); break;
		case 6: get_s(mas, n); break;
		case 7: add_comp(mas, n); break;
		case 8: del_compl(mas, n); break;
		case 99: break;
		}
		if (choice == 99) break;
	}
	delete[]mas;

	return 0;
}