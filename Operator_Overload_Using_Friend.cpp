#include <iostream>

using namespace std;

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int n, int d) : m_numerator(n), m_denominator(d) {
		reduce();
	}
	~Fraction(){}

	void print() {
		cout << m_numerator << "/" << m_denominator << endl;
	}

	static int gcd(int a, int b){
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}

	void reduce(){
		if (m_numerator != 0 && m_denominator != 0)	{
			int gcd(gcd(m_numerator, m_denominator));
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
	
	friend Fraction operator *(const Fraction& obj1); // The prototype for the operator overload function on row 38
	friend Fraction operator *(const Fraction& obj1, const Fraction& obj2);
	friend Fraction operator *(const Fraction& obj1, int value);
	friend Fraction operator *(int value, const Fraction& obj2);
};

Fraction operator *(const Fraction& obj1) {		  // This form of overload can be used as well.
	Fraction temp;

	temp.m_numerator = m_numerator + obj1.m_numerator
	temp.m_denominator = m_denominator + obj1.m_denominator

	return temp;
}

Fraction operator *(const Fraction& obj1, const Fraction& obj2) {
	int obj_numerator = obj1.m_numerator * obj2.m_numerator;
	int obj_denominator = obj1.m_denominator * obj2.m_denominator;
	return { obj_numerator, obj_denominator };
}
Fraction operator *(const Fraction& obj1, int value) {
	int obj_numerator = obj1.m_numerator * value;
	int obj_denominator = obj1.m_denominator;
	return { obj_numerator, obj_denominator };
}
Fraction operator *(int value, const Fraction& obj2) {
	int obj_numerator = obj2.m_numerator * value;
	int obj_denominator = obj2.m_denominator;
	return { obj_numerator, obj_denominator };
}

int main() {

	Fraction f1( 2, 5 );
	f1.print();

	Fraction f2( 3, 8 );
	f2.print();

	Fraction f3( f1 * f2 );
	f3.print();

	Fraction f4( f1 * 2 );
	f4.print();

	Fraction f5( 2 * f2 );
	f5.print();

	Fraction f6( Fraction(1, 2) *Fraction(2, 3) *Fraction(3, 4) );
	f6.print();

	Fraction f7( 0, 6 );
	f7.print();

	return 0;
}
