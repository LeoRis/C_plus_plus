#include <iostream>

using namespace std;

class Car {

private:
	string Color;
	double Price;

protected:
	string Name;
	bool IsBroken;

public:
	Car(string name, string color, double price) {
		Name = name;
		Color = color;
		Price = price;
		IsBroken = false;
	}

	void getInfo() {
		cout << "Name: " << Name << endl;
		cout << "Color: " << Color << endl;
		cout << "Price: " << Price << " $" << endl;
	}

	void crashedCar() {
		cout << Name << " crashed" << endl;
		IsBroken = true;
	}

	void repairCar() {
		cout << Name << " repaired" << endl;
		IsBroken = false;
	}

	void move() {
		if (IsBroken) {
			cout << Name << " broken" << endl;
		}
		else {
			cout << Name << " is driving" << endl;
		}
	}
};

class FlyingCar : public Car {

public:
	FlyingCar(string name, string color, double price) :Car(name, color, price) {	
	}
	void move() {
		if (IsBroken) {
			cout << Name << " broken" << endl;
		}
		else {
			cout << Name << " is flying" << endl;
		}
	}
};

class UnderwaterCar : public Car {

public:
	UnderwaterCar(string name, string color, double price) :Car(name, color, price) {
	}
	void move() {
		if (IsBroken) {
			cout << Name << " broken" << endl;
		}
		else {
			cout << Name << " is diving" << endl;
		}
	}
};

int main()
{
	Car ford("Ford", "Black", 50000);
	FlyingCar flyingCar("Tesla", "Blue", 3000000);
	UnderwaterCar underwaterCar("Nemo", "turquoise", 700000);

	ford.move();
	flyingCar.move();
	underwaterCar.move();

	Car* car1 = &flyingCar;
	Car* car2 = &underwaterCar;

	car1->crashedCar();
	car2->crashedCar();

	ford.move();
	flyingCar.move();
	underwaterCar.move();

	car1->repairCar();
	car2->repairCar();

	ford.move();
	flyingCar.move();
	underwaterCar.move();

	system("pause>20");
}
