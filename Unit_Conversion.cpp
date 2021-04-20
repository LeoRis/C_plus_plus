#include <iostream>

using namespace std;

class Base {
protected:
	double initial_value;
	double converted_value;

public:
	Base() {}
	Base(double initValue, double convValue = 0.0) : initial_value(initValue), converted_value(convValue){}
	~Base() {}

	virtual void compute() = 0;
	virtual void print() = 0;

	double get_Init() { return initial_value; }
	double get_Conv() { return converted_value; }
};

class Gallon_To_Liter : public Base {
public:
	Gallon_To_Liter(){}
	Gallon_To_Liter(double initValue, double convValue = 0.0) : Base(initValue, convValue){}
	~Gallon_To_Liter(){}

	void compute() { converted_value = get_Init() * 3.785; }
	
	void print() { cout << "The converted value is: " << get_Conv() << endl; }
};

class Fahrenheit_To_Celsius : public Base {
public:
	Fahrenheit_To_Celsius(){}
	Fahrenheit_To_Celsius(double initValue, double convValue = 0.0) : Base(initValue, convValue) {}
	~Fahrenheit_To_Celsius(){}

	void compute() { converted_value = (get_Init() - 32) * (5.0 / 9.0); }

	void print() { cout << "The converted value is: " << get_Conv() << endl; }
};

class Feet_To_Meter : public Base {
public:
	Feet_To_Meter(){}
	Feet_To_Meter(double initValue, double convValue = 0.0) : Base(initValue, convValue) {}
	~Feet_To_Meter(){}

	void compute() { converted_value = initial_value / 3.281; }

	void print() { cout << "The converted value is: " << get_Conv() << endl; }
};

int main() {

	Base* ptr = nullptr;

	Gallon_To_Liter User1(100.00);
	Fahrenheit_To_Celsius User2(80.00);
	Feet_To_Meter User3(280.00);

	ptr = &User1;

	cout << ptr->get_Init() << " gallons are ";
	ptr->compute();
	cout << ptr->get_Conv() << " liters." << endl;

	ptr = &User2;

	cout << ptr->get_Init() << " Fahrenheit are ";
	ptr->compute();
	cout << ptr->get_Conv() << " Celsius." << endl;

	ptr = &User3;

	cout << ptr->get_Init() << " feet are ";
	ptr->compute();
	cout << ptr->get_Conv() << " meter." << endl;

	return 0;
}