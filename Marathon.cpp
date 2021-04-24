#include <iostream>

using namespace std;

class Ucesnik {
private:
	char* ime;
	bool pol;
	int vozrast;

public:
	Ucesnik(){}
	Ucesnik(char* name, bool sex, int age) {
		ime = new char[strlen(name)];
		strcpy(ime, name);
		vozrast = age;
		pol = sex;
	}
	Ucesnik(const Ucesnik& obj) {
		ime = new char[strlen(obj.ime)];
		pol = obj.pol;
		vozrast = obj.vozrast;
	}
	~Ucesnik() { delete[] ime; }

	int get_Vozrast() { return vozrast; }

	string get_Ime() { return string(ime); }

	friend bool operator > (const Ucesnik& obj1, const Ucesnik& obj2) {
		if (obj1.vozrast > obj2.vozrast) {
			return true;
		}
		else {
			return false;
		}
	}

	friend ostream& operator << (ostream& out, Ucesnik& obj) {
		out << "Ime:" << obj.ime << endl;
		out << "Pol: ";
		if (obj.pol) {
			out << " maski pol" << endl;
		}
		else {
			out << "zenski pol" << endl;
		}
		out << "Vozrast: " << obj.vozrast << endl;
		return out;
	}
};

class Maraton : public Ucesnik {
private:
	char lokacija[100];
	Ucesnik* ucesnik;
	int broj_na_ucesnici;

public:
	Maraton() : Ucesnik(){} // dali treba da nasledi default const. od base class?
	Maraton(char* name, bool sex, int age, char* location, Ucesnik* _ucesnik, int number)
		: Ucesnik(name, sex, age) {
		strncpy(lokacija, location, 99);
		lokacija[99] = '\0';
		broj_na_ucesnici = number;
		ucesnik = new Ucesnik[number];	
		for(int i = 0; i < broj_na_ucesnici; i++){
			ucesnik[i] = _ucesnik[i];
		}
	}
	Maraton(const Maraton& obj) : Ucesnik(obj){
		strncpy(lokacija, obj.lokacija, 99);
		lokacija[99] = '\0';
		broj_na_ucesnici = obj.broj_na_ucesnici;
		for (int i = 0; i < broj_na_ucesnici; i++) {
			ucesnik[i] = obj.ucesnik[broj_na_ucesnici];
		}
	}
	~Maraton() { delete[] ucesnik; }

	Maraton& operator = (Maraton& obj) {
		if (this != &obj) {
			delete[] ucesnik;
			broj_na_ucesnici = obj.broj_na_ucesnici;
			ucesnik = new Maraton[obj.broj_na_ucesnici];
			for (int i = 0; i < broj_na_ucesnici; i++) {
				ucesnik[i] = obj.ucesnik[i];
			}
		}
		return *this;
	}

	Maraton& operator += (Ucesnik& obj) {
		Ucesnik* temp = new Ucesnik[broj_na_ucesnici + 1];
		for (int i = 0; i < broj_na_ucesnici; i++) {
			temp[i] = ucesnik[i];
		}
		delete[] ucesnik;
		ucesnik = temp;
		ucesnik[broj_na_ucesnici] = obj;
		broj_na_ucesnici++;
		return *this;
	}

	int procesnaVozrast() {
		return get_Vozrast() / broj_na_ucesnici;
	}

	void pecatiPomladi(Ucesnik& u) {
		for (int i = 0; i < broj_na_ucesnici; i++) {
			if (ucesnik->get_Vozrast() < u.get_Vozrast()) {
				cout << ucesnik->get_Ime();
			}
			else {
				continue;
			}
		}
	}
};

int main() {

	return 0;
}