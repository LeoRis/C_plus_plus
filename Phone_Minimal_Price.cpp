#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

class Telephone {
protected:
	int production_year;
	int starting_price;
	char telephone_model[40];

public:
	Telephone() {}
	Telephone(int prodYear, int startPrice, const char* teleModel) {
		production_year = prodYear;
		starting_price = startPrice;
		strncpy(telephone_model, teleModel, strlen(telephone_model));
		telephone_model[39] = '\0';
	}
	Telephone(const Telephone& obj) {
		production_year = obj.production_year;
		starting_price = obj.starting_price;
		strcpy(telephone_model, obj.telephone_model);
	}
	~Telephone() {}

	virtual float Calculate_Value() = 0;

	friend bool operator < (Telephone& t1, Telephone& t2) {
		return t1.Calculate_Value() < t2.Calculate_Value();
	}

	void set_Production_Year(int prodYear) { production_year = prodYear; }
	void set_Starting_Price(int startPrice) { starting_price = startPrice; }
	void set_Telephone_Model(char* teleModel) { strcpy(telephone_model, teleModel); }

	int get_Production_Year() { return production_year; }
	int get_Starting_Price() { return starting_price; }
	char get_Telephone_Model() { return *telephone_model; }

	void print() {
		cout << "Year: " << get_Production_Year() << endl;
		cout << "Price: " << get_Starting_Price() << endl;
		cout << "Model: " << get_Telephone_Model() << endl;
	}

	friend ostream& operator << (ostream& out, const Telephone& obj) {
		//out << obj.production_year;
		//out << obj.starting_price;
		//out << obj.telephone_model;
		//return out;
		return out << obj.production_year << ", " << obj.starting_price << ", " << obj.telephone_model;
	}
};

class Mobile_Phone : public Telephone {
protected:
	double mp_width;
	double mp_heigth;
	double mp_thickness;

public:
	Mobile_Phone() {}
	Mobile_Phone(int prodYear, int startPrice, const char* teleModel, double width, double heigth, double thick) : Telephone(prodYear, startPrice, teleModel) {
		mp_width = width;
		mp_heigth = heigth;
		mp_thickness = thick;
	}
	Mobile_Phone(const Mobile_Phone& obj) : Telephone(obj) {
		mp_width = obj.mp_width;
		mp_heigth = obj.mp_heigth;
		mp_thickness = obj.mp_thickness;
	}
	~Mobile_Phone() {}

	void set_mp_width(double width) { mp_width = width; }
	void set_mp_heigth(double heigth) { mp_heigth = heigth; }
	void set_mp_thickness(double thick) { mp_thickness = thick; }

	double get_mp_width() { return mp_width; }
	double get_mp_heigth() { return mp_heigth; }
	double get_mp_thickness() { return mp_thickness; }

	float Calculate_Value() {
		if (get_Production_Year() < 2010) {
			starting_price = (double)get_Starting_Price() + (double)get_Starting_Price() * 0.95 / 100.00;
		}
		if (get_mp_thickness() < 0.7) {
			starting_price = get_Starting_Price() + get_Starting_Price() * 5 / 100;
		}
		return starting_price;
	}

	friend ostream& operator << (ostream& out, const Mobile_Phone& obj) {
		//out << obj.mp_width;
		//out << obj.mp_heigth;
		//out << obj.mp_thickness;
		//return out;
		return out << obj.mp_width << ", " << obj.mp_heigth << ", " << obj.mp_thickness;
	}
};

class Fixed_Phone : public Telephone {
protected:
	int fp_weigth;

public:
	Fixed_Phone() {}
	Fixed_Phone(int prodYear, int startPrice, const char* teleModel, int weigth) : Telephone(prodYear, startPrice, teleModel), fp_weigth(weigth) {}
	Fixed_Phone(const Fixed_Phone& obj) : Telephone(obj) { fp_weigth = obj.fp_weigth; }

	void set_fp_weigth(int weigth) { fp_weigth = weigth; }
	int get_fp_weigth() { return fp_weigth; }

	float Calculate_Value() {
		if (get_Production_Year() < 2009) {
			starting_price = (double)get_Starting_Price() + (double)get_Starting_Price() * 0.98 / 100.00;
		}
		if (get_fp_weigth() < 100) {
			starting_price = get_Starting_Price() + get_Starting_Price() * 7 / 100;
		}
		return starting_price;
	}

	friend ostream& operator << (ostream& out, const Fixed_Phone& obj) {
		//out << obj.fp_weigth;
		//return out;
		return out << obj.fp_weigth;
	}
};

void compare(Telephone** ptr, int number) {
	Telephone* min = ptr[0];
	for (int i = 0; i < number; i++) {
		if ((*ptr[i]) < *min) {
			min = ptr[i];
		}
	}
	cout << min->Calculate_Value() << endl;
};

int main() {

	Mobile_Phone M1(2005, 1500, "NOKIA", 10.5, 1.5, 0.7);
	Mobile_Phone M2(2011, 1500, "SAMSUNG", 7.5, 0.5, 1.1);

	Fixed_Phone F1(2009, 10000, "IPHONE", 80);

	cout << "M1: " << M1.Calculate_Value() << endl;
	cout << "M2: " << M2.Calculate_Value() << endl;
	cout << "F1: " << F1.Calculate_Value() << endl;

	Telephone** Telephones = new Telephone * [3];
	Telephones[0] = &M1;
	Telephones[1] = &M2;
	Telephones[2] = &F1;

	cout << "The minimal price is: "; compare(Telephones, 3);

	return 0;
}