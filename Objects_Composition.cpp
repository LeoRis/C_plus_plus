#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

class Charr {
	enum { CharrSize = 40 };

private:
	char arr[CharrSize + 1];

public:
	Charr(const char* a) {
		cout << "\t\t*Constructing Charr: " << a << endl;
		strncpy(arr, a, CharrSize);
		arr[CharrSize] = '\0';
	}
	~Charr() {
		cout << "\t\t#Destructing Charr: " << arr << endl;
	}
	void Show() const {
		cout << arr;
	}
};

class Person {
private:
	Charr firstName;
	Charr lastName;
	int level;

public:
	Person(int lv, const char* fname, const char* lname) : level(lv), firstName(fname), lastName(lname) {
		cout << "\t\t*Constructing Person: " << fname << ' ' << lname << ' ' << lv << endl;
	}
	~Person() {
		cout << "\t\t#Destructing Person: ";
		firstName.Show();
		cout << ' ';
		lastName.Show();
		cout << ' ';
		cout << level << endl;
	}
	void Show(void) const {
		firstName.Show();
		cout << ' ';
		lastName.Show();
		cout << ' ';
		cout << level;
	}
};

int main() {
	Charr a("Hello ");
	const Charr b("World");

	Person y(1, "Al", "Capone");
	a.Show();

	cout << endl;
	{
		Person x(1, "Marlon", "Brando");
		x.Show();
		cout << endl;
		y.Show();
		cout << endl;
	}

	b.Show();
	cout << endl;
}
