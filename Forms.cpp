#include <iostream>
#include <cstring>
#include <cmath>

#pragma warning(disable : 4996)

using namespace std;

const double PI = 3.1415926535;

class Forma {
private:
	char boja[7];
	int m_x;
	int m_y;

public:
	Forma() {}
	Forma(const char* color, int x, int y) : m_x(x), m_y(y) { strcpy(boja, color); }
	Forma(const Forma& obj) : m_x(obj.m_x), m_y(obj.m_y) { strcpy(boja, obj.boja); }
	~Forma() {}

	friend ostream& operator << (ostream& out, Forma& obj) {
		out << "Boja: " << obj.boja << endl;
		out << "X = " << obj.m_x << ", " << "Y = " << obj.m_y << endl;
		out << "Plostina = " << obj.plostina() << endl;
		return out;
	}

	friend bool operator > (Forma& obj1, Forma& obj2) { return obj1.plostina() > obj2.plostina(); }

	virtual int plostina() = 0;

	friend void top3(Forma** formi, int broj);

};

class Elipsa : public Forma {
private:
	int polovina_od_glavna_oska_a;
	int polovina_od_sporedna_oska_b;

public:
	Elipsa() : Forma() {}
	Elipsa(const char* color, int x, int y, int a, int b) : Forma(color, x, y), polovina_od_glavna_oska_a(a), polovina_od_sporedna_oska_b(b) {}
	Elipsa(const Elipsa& obj) : Forma(obj) {
		polovina_od_glavna_oska_a = obj.polovina_od_glavna_oska_a;
		polovina_od_sporedna_oska_b = obj.polovina_od_sporedna_oska_b;
	}
	~Elipsa() {}

	int get_A() { return polovina_od_glavna_oska_a; }
	int get_B() { return polovina_od_sporedna_oska_b; }

	int plostina() {
		return PI * (double)get_A() * (double)get_B();
	}
};

class Kvadrat : public Forma {
private:
	int dolzina_strana_a;

public:
	Kvadrat() : Forma() {}
	Kvadrat(const char* color, int x, int y, int a) : Forma(color, x, y), dolzina_strana_a(a) {}
	Kvadrat(const Kvadrat& obj) : Forma(obj), dolzina_strana_a(obj.dolzina_strana_a) {}
	~Kvadrat() {}

	int get_A() { return dolzina_strana_a; }

	int plostina() { return pow((double)get_A(), 2.0); }
};

void top3(Forma** formi, int broj) {
	int i = 0;
	int j = 0;
	int k = 0;
	Forma* temp = nullptr;
	for (i = 1; i < broj; i++) {
		for (j = 0; j < broj - i; j++) {
			if (*formi[j] > *formi[j + 1]) {
				temp = formi[j + 1];
				formi[j + 1] = formi[j];
				formi[j] = temp;
			}
		}
	}
	for (k = broj - 1; k >= 0; k--) {
		cout << *formi[k] << endl;
	}
}

int main() {

	Forma** niza;
	int n, a, b, x, y;
	char buja[7];
	cin >> n;
	niza = new Forma * [n * 2];
	for (int i = 0; i < n; i++) {
		cin >> buja;
		cin >> x >> y;
		cin >> a;
		cin >> b;
		niza[i] = new Elipsa(buja, x, y, a, b);
	}
	for (int i = n; i < n * 2; i++) {

		cin >> buja;
		cin >> x >> y;
		cin >> a;
		niza[i] = new Kvadrat(buja, x, y, a);
	}
	top3(niza, n * 2);
	delete[] niza;

	return 0;
}