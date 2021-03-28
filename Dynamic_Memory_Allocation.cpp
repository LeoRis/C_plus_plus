#include <iostream>

using namespace std;

class MyClass {
private:
	int i;
	
public:
	MyClass() { cout << "Default constructor." << endl; }
	MyClass(int a) : i(a) { cout << "Parametarized (" << a << ") constructor." << endl; }
	~MyClass() { cout << "Destructor for " << i << " called." << endl; }

	void show() const { cout << i << endl; }
};

int main() {
	MyClass* ip = new MyClass();
	MyClass* jp = new MyClass(2);
	MyClass* arrayP = new MyClass[4];

	ip->show();
	(*jp).show();

	for (int i = 0; i < 4; i++) {
		cout << "arrayP[" << i << "]=";
		arrayP[i].show();
	}

	delete ip;
	delete jp;
	delete[] arrayP;
}