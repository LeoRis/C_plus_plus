#include <iostream>

using namespace std;

class MyClass {
	private:
		int i;
	public:
		MyClass(int n){
			i = n;
			cout << "Constructing " << i << endl;
		}
		~MyClass() {
			cout << "Destroying " << i << endl;
		};
		void set_i(int n) { i = n; };
		int get_i() { return i; };
};

void f(MyClass obj);

int main(){
	MyClass o(1);
	f(o);

	cout << "This is i in main: " << o.get_i() << endl;

	return 0;
}

void f(MyClass obj) {
	obj.set_i(2);
	cout << "This is local i: " << obj.get_i() << endl;
}