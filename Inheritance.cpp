#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
	enum { small = 1, medium = 2, large = 3 };
	int m_Size;
	int m_Year;
	int m_Mileage;

public:
	Vehicle(){}
	Vehicle(int size) : m_Size(size){}
	Vehicle(Vehicle& obj) : m_Size(obj.m_Size), m_Year(obj.m_Year), m_Mileage(obj.m_Mileage){}
	~Vehicle(){}

	Vehicle& set_Mileage(int mileage){
		m_Mileage = mileage;
		return *this;
	}

	Vehicle& set_Year(int year) {
		m_Year = year;
		return *this;
	}

	Vehicle& set_Size(int size) {
		m_Size = size;
		return *this;
	}

	virtual void print() {
		cout << m_Size << ' ' << m_Year << ' ' << m_Mileage << endl;
	}

	Vehicle operator = (const Vehicle& obj) {
		if (this != &obj) {
			m_Size = obj.m_Size;
			m_Year = obj.m_Year;
			m_Mileage = obj.m_Mileage;
		}
		return *this;
	}
};

class Terrain_Vehicle : public Vehicle {
private:
	int wheel_Number;
	string Model;

public:
	Terrain_Vehicle(){}
	Terrain_Vehicle(int size, int wheel_number, string model)
		: Vehicle(size), wheel_Number(wheel_number), Model(model){}
	Terrain_Vehicle(Terrain_Vehicle& obj) : Vehicle(obj){}
	~Terrain_Vehicle(){}

	void print() {
		cout << m_Size << ' ' << m_Year << ' ' << m_Mileage << ' ' <<wheel_Number << ' ' << Model << endl;
	}

	Terrain_Vehicle operator = (const Terrain_Vehicle& obj) {
		if (this != &obj) {
			m_Size = obj.m_Size;
			m_Year = obj.m_Year;
			m_Mileage = obj.m_Mileage;
			wheel_Number = obj.wheel_Number;
			Model = obj.Model;
		}
		return *this;
	}
};

class Car : public Terrain_Vehicle {
private:
	string Manufacturer;
	int Doors;
	string Color;

public:
	Car(){}
	Car(int size, int wheel_Number, string Model, string manufacturer, int doors, string color)
		: Terrain_Vehicle(size, wheel_Number, Model), Manufacturer(manufacturer), Doors(doors), Color(color){}
	~Car(){}

	void print() {
		cout << m_Size << ' ' << m_Year << ' ' << m_Mileage << ' ' << Manufacturer << ' ' << Doors << ' ' << Color << endl;
	}

	Car& set_Manufacturer(string manufacturer) {
		Manufacturer = manufacturer;
		return *this;
	}

	Car& set_Doors(int doors) {
		Doors = doors;
		return *this;
	}

	Car& set_Color(string color) {
		Color = color;
		return *this;
	}
};

class Amphibious_Vehicle : public Vehicle {
private:
	int Depth;
	string Fuel;

public:
	Amphibious_Vehicle(int size, int depth, string fuel) : Vehicle(size), Depth(depth), Fuel(fuel){}
	~Amphibious_Vehicle() {}

	void print() {
		cout << m_Size << ' ' << m_Year << ' ' << m_Mileage << ' ' << Depth << ' ' << Fuel << endl;
	}
};

int main() {

	Vehicle Transport;

	Terrain_Vehicle Train(3, 20, "Train");
	Terrain_Vehicle Jeep;
	Jeep.set_Year(1990).set_Size(1).set_Mileage(100);
	Transport = Jeep;
	Transport.print();

	Amphibious_Vehicle Boat(3, 100, "Petrol");

	Train.set_Year(1960);
	Train.set_Mileage(1000000);
	
	Boat.set_Year(2000);
	Boat.set_Mileage(500000);

	Train.print();
	Boat.print();
	
	Car GT40;
	GT40.set_Manufacturer("Ford").set_Doors(small).set_Color("Blue").set_Size(2).set_Year(2020).set_Mileage(500);
	GT40.print();
}
