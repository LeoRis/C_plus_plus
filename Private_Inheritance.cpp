#include <iostream>

using namespace std;

class Pet {
public:
	char eat() const { return 'a'; }
	int speak() const { return 2; }
	float sleep() const { return 3.0; }
	float sleep(int) const { return 4.0; }
};

class Goldfish : Pet {
public:
	using Pet::eat;
	using Pet::sleep;
};

int main() {

	Goldfish Bob;
	Bob.eat();
	Bob.sleep();
	Bob.sleep(2);

	return 0;
}