#include <iostream>

using namespace std;

class Demo {
private:
	int x, y, z;

public:
	Demo(int a, int b, int c) : x(a), y(b), z(c) {}
	~Demo() {}

	void print() {
		cout << "x = " << x << " y = " << y << " z = " << z << endl;
	}

	void operator - () {
		x--;
		y--;
		z--;
	}

	void operator + () { x++; y++; z++; }
};

int main() {
	Demo Test(10, 20, 30);

	Test.print();

	-Test;

	Test.print();

	+Test;

	Test.print();
}