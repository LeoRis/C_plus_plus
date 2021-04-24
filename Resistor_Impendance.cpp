#include <iostream>
#include <cmath>

using namespace std;

class Resistor {
private:
	double R;

public:
	//Resistor(){} //WHy it's not working with this default constr?
	Resistor(double rR = 1) : R(rR){}
	//~Resistor(){}

	double get_R() { return R; }
	void set_R(double rR) { R = rR; }

	virtual double module() { return R; }

	double charge(double I) { return I * module(); }

	Resistor operator + (Resistor& obj) {
		Resistor temp;
		temp.R = R + obj.R;
		return temp;
	}

	friend ostream& operator << (ostream& out, Resistor& obj) {
		return out << "Z= " << obj.R << " oms";
	}
};

class Impedance : public Resistor {
private:
	double X;

public:
	//Impedance(){}
	Impedance(double rR = 1, double xX = 1) : Resistor(rR), X(xX){}
	//~Impedance(){}

	virtual double module() { return sqrt(get_R() * get_R() + X * X); }

	Impedance operator + (Impedance& obj) {
		Impedance temp;
		temp.set_R(get_R() + obj.get_R());
		temp.X = X + obj.X;
		return temp;
	}

	Impedance operator + (Resistor& obj) {
		Impedance temp;
		temp.set_R(get_R() + obj.get_R());
		temp.X = X;
		return temp;
	}

	friend Impedance operator + (Resistor& obj1, Impedance& obj2) {
		Impedance temp;
		temp.set_R(obj1.get_R() + obj2.get_R());
		temp.X = obj2.X;
		return temp;
	}

	friend ostream& operator << (ostream& out, Impedance& obj) {
		return out << "Z = " << obj.get_R() << " + j " << obj.X << " oms";
	}
};

int main() {

	Resistor R1(10), R2, R3(3);
	Impedance L1(3, 10), L2, L3(4);

	Resistor* ptr;

	cout << R1 << endl << L1 << endl;
	cout << R2 << endl << L2 << endl;

	ptr = &L1;

	cout << "For I = 5 A, U = " << ptr->charge(5) << " V\n";

	R3 = R1 + R2;
	cout << R3 << endl;

	L3 = L1 + L2;
	cout << L3 << endl;

	L3 = L2 + R1;
	cout << L3 << endl;

	L3 = R1 + L2;
	cout << L3 << endl;

	return 0;
}