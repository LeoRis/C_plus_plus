#include <iostream>
#include <cstring>

using namespace std;

class Rational {
public:
	Rational(int n = 0, int d = 1) : num(n), den(d) // More powerfull option for initializing variables.
							// Const members and reference members can only be initialized in an initialization list.
	{
		//num = n;	Variable initialization can be done it both ways.
		//den = d;	
		reduce();
	}
	Rational(const Rational& r) : num(r.num), den(r.den) {
		//num = r.num;
		//den = r.den;
	}
	void print() const {
		cout << num << '/' << den;
	}
	~Rational(){}

private:
	int num, den;
	int gcd(int m, int n) {
		if (n == 0) {
			return m;
		}
		else {
			return gcd(n, m % n);
		}
	}
	void reduce() {
		int g = gcd(num, den);
		num /= g;
		den /= g;
	}
};

int main() {
	Rational x(100, 360);
	Rational y(x);

	cout << "X = "; 
	x.print();

	cout << ", y = ";
	y.print();

	return 0;
}
