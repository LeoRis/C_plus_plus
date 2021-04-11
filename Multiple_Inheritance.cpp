#include <iostream>
#include <string>

using namespace std;

class Human {
public:
	string Name;
	int Age;
	Human(string name, int age) : Name(name), Age(age) { cout << "Human creator." << endl; }
	~Human() { cout << "Human destro." << endl; }

	virtual void print() {
		cout << "My name is " << Human::Name << "." << "I am " << Human::Age << " years old." << endl;
	}

};

class Religion {
public:
	string Type;
	Religion(string type) : Type(type) { cout << "Religion creator." << endl; }
	~Religion() { cout << "Religion destro." << endl; }
};

class European : public Human, public Religion{
private:
	int Height;

public:
	European(string name, int age, string type, int height) : Human(name, age), Religion(type), Height(height) { cout << "European creator." << endl; }
	~European() { cout << "European destro." << endl; }

	void print() {
		cout << "My name is " << Human::Name << "." << "I am " << Human::Age << " years old." << "I am " << Height << " high." << "I am a " << Religion::Type << "." << endl;
	}
};

int main() {

	European Person("John", 32, "Jew", 195);
	Person.print();

}
