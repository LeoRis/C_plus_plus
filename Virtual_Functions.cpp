#include <iostream>

using namespace std;

class Base {
public:
	virtual int f() const {
		cout << "Base::f()\n";
		return 1;
	}
	virtual char f(string a) const { 
		cout << a << endl;
		return 0; }
	virtual void g() const {}
};

class Derived1 : public Base {
public:
	void g() const {}
};

class Derived2 : public Base {
public:
	int f() const {
		cout << "Derived2::f()\n";
		return 2;
	}
};

class Derived3 : public Base {
public:

};

class Derived4 : public Base {
public:
	int f(int) const {
		cout << "Derived4::f()\n";
		return 4;
	}
};

int main() {

	string s("Hello");
	Derived1 d1;
	
	int x = d1.f();
	char c = d1.f(s);

	Derived2 d2;

	x = d2.f();
	//c = d2.f(s);		// String version hidden

	Derived4 d4;
	
	x = d4.f(1);
	//x = d4.f();			// f() version hidden
	//d4.f(s);			// String version hidden

	Base& br = d4;		// Upcast
	//br.f(1);			// Derived version unavailable

	br.f();
	br.f(s);

}