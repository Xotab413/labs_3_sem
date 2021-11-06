#include<iostream>
#include<cmath>
using namespace std;
class Compl {
	int a;
	int b;
public:

	Compl(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}
	void input() {
		cout << "Input new number " << endl;
		cin >> a;
		cin >> b;
	}
	Compl& operator--() { //--A
		this->a--;
		this->b--;
		return *this;
	}
	Compl operator--(int) { // A--
		Compl obj(this->a, this->b);
		this->a--;
		this->b--;
		return obj;
	}

	Compl& operator-(Compl& other) {
		Compl buf(a - other.a, b - other.b);
		return buf;
	}
	bool operator> (Compl& obj2) {
		if (double(*this) > double(obj2)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator< (Compl& obj2) {
		if (double(*this) < double(obj2)) {
			return true;
		}
		else {
			return false;
		}
	}
	Compl& operator=(Compl& other) {
		if (this != &other) {
			this->a = other.a;
			this->b = other.b;
		}
		return *this;
	}
	Compl& operator=(int a) {
		this->a = a;
		this->b = 0;
		return *this;
	}
	Compl& operator+(Compl& other) {
		Compl buf(this->a + other.a, this->b + other.b);
		return buf;
	}
	void operator() (int n) {
		double z = double(*this);
		double s = atan(double(this->b) / this->a);
		this->a = round(pow(z, n) * cos(s * n));
		this->b = round(pow(z, n) * sin(s * n));
	}

	Compl operator++(int) { //A++
		Compl obj(a, b);


		this->a++;
		this->b++;
		return obj;

	}
	Compl& operator++() { // ++A
		this->a++;
		this->b++;
		return *this;
	}
	bool operator ==(Compl& other) {
		if (this->a == other.a && this->b == other.b) {
			return true;
		}
		else {
			return false;
		}
	}

	operator double() {
		return sqrt(this->a * this->a + this->b * this->b);
	}
	void show() {
		if (a == 0 && b == 0) {
			cout << 0;
		}
		else if (b == 0 && a != 0) {
			cout << a;
		}
		else if (b != 0 && a == 0) {
			cout << b << "i";
		}
		else if (b < 0) {
			cout << a << b << "i";
		}

		else if (b > 0) {
			cout << a << "+" << b << "i";
		}

	}
	int get_i() { return b; }
	int get_c() { return a; }
};





