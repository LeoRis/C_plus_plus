#include <iostream>
#include <cmath>

using namespace std;

class Product {
private:
	double m_price;

public:
	Product() {};
	Product(double price) : m_price(price) { }
	~Product(){}

	double get_Price() const { return m_price; }

	double set_Price(double new_Price) {
		if (new_Price >= 0) {
			m_price = new_Price;
		}
		else {
			cout << "Can not have a negative price!" << endl;
		}
	}

	virtual double bill() const {
		return m_price;
	};

	double calculate_Savings(const Product& obj) const {
		return (bill() - obj.bill());
	}

	friend bool operator < (const Product& obj1, const Product& obj2) {
		if (obj1.m_price < obj2.m_price) {
			return false;
		}
		else {
			return true;
		}

		//return (obj1.bill() < obj2.bill())	// This works the same.

	}

	friend ostream& operator << (ostream& out, const Product& obj) {
		return out << obj.m_price << endl;
	}
};

class Discount : public Product {
private:
	double charge_discount;

public:
	Discount(){}
	Discount(double price, double discount) : Product(price), charge_discount(discount){}
	~Discount(){}

	double bill() const {
		double fraction = charge_discount / 100;
		return (1 - fraction) * get_Price();
	}
};

void compare(const Product& obj1, const Product& obj2) {
	if (obj1 < obj2) {
		cout << "The first is cheaper" << endl;
	}
	else {
		cout << "The second is cheaper" << endl;
	}
	cout << "Savings: " << fabs(obj2.calculate_Savings(obj1)) << endl;
}

int main() {

	Product simple(10.00);
	Discount discount(11.00, 10);

	compare(simple, discount);
	
	return 0;
}