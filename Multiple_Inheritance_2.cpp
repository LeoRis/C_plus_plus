#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

class Trailer {
private:
	int m_weight;

public:
	Trailer() {}
	Trailer(int weight) : m_weight(weight){}

	void set_weight(int weight) { m_weight = weight; }
	int get_weight() const { return m_weight; }

	virtual void print() { cout << m_weight << endl; }
};

class Auto {
protected:
	int m_engine_weight;
	int m_sp;
	char m_auto_name[10];

public:
	Auto() {};
	Auto(int eng_w, int sp, const char* name) : m_engine_weight(eng_w), m_sp(sp) {
		strcpy(m_auto_name, name);
	}
	void set_weight(int weight) { m_engine_weight = weight; }
	int get_weight() const { return m_engine_weight; }

	void print() {
		cout << "The vehicle name is: " << m_auto_name << endl;
		cout << "The engine weight is: " << m_engine_weight << endl;
		cout << "The engine SP is: " << m_sp << endl;
	}
};

class Truck : public Trailer, public Auto {
private:
	int m_trailer_weight;

public:
	Truck(){}
	Truck(int eng_w, int sp, const char* name, int trailer_weight) : Auto(eng_w, sp, name), Trailer(trailer_weight), m_trailer_weight(trailer_weight){}

	void set_weight(int eng_w, int trailer_weight) {
		Auto::set_weight(eng_w);
		Trailer::set_weight(trailer_weight);
	}
	int get_weight() const { return (Trailer::get_weight() + Auto::get_weight()); }

	void print() { 
		cout << "The truck's name is: " << m_auto_name << endl;
		cout << "The truck's weight is: " << get_weight() << endl; }

};


int main() {

	Truck Mercedes(2000, 154, "Benz", 700);

	Mercedes.set_weight(2000, 700);
	Mercedes.get_weight();

	Mercedes.print();

}