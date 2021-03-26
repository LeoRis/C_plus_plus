#include <iostream>
#include <string>

using namespace std;

class Cars {
private:
	string company_name;
	string model_name;
	string fuel_type;
	float mileage;
	double price;

public:

	// default constructor
	Cars() {
		cout << "Default constructor called." << endl;
	}

	// parametarized constructor
	Cars(string cname, string mname, string ftype, float m, double p) {
		cout << "Parameterized constructor called." << endl;
		company_name = cname;
		model_name = mname;
		fuel_type = ftype;
		mileage = m;
		price = p;
	}

	// copy constructor
	Cars(Cars& obj) {
		cout << "Copy constructor called" << endl;
		company_name = obj.company_name;
		model_name = obj.model_name;
		fuel_type = obj.fuel_type;
		mileage = obj.mileage;
		price = obj.price;
	}

	void setData(string cname, string mname, string ftype, float m, double p) {
		company_name = cname;
		model_name = mname;
		fuel_type = ftype;
		mileage = m;
		price = p;
	}

	void displayData() {
		cout << "Car properties: " << endl;
		cout << "Car Company Name - " << company_name << endl;
		cout << "Car Model Name - " << model_name << endl;
		cout << "Car Fuel Type - " << fuel_type << endl;
		cout << "Car Mileage - " << mileage << endl;
		cout << "Car Price - " << price << endl;
	}

	~Cars() {
		cout << "Destructor called." << endl;
	}
};

int main() {
	
	Cars car1, car2("Ferrari", "Portofino M", "Petrol", 50000, 12000000);
	car1.setData("Ferrari", "SF90 Spider", "Petrol", 150000, 50000000);
	car1.displayData();
	car2.displayData();

	Cars car3 = car1;
	car3.displayData();
}