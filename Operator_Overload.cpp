#include <iostream>

// Operators we can't overload:
// A. ::
// B. ?:
// C. .
// D. .*
// E. sizeof
// F. typeid

using namespace std;

class Box {
public:
	double length, width, breadth;
	string boxString;

	Box() { length = 1; width = 1; breadth = 1; }
	Box(double l, double w, double b) : length(l), width(w), breadth(b){}

	Box operator ++ () { length++; width++; breadth++; return *this; }
	Box operator + (const Box& box2) {
		Box boxSum;
		boxSum.length = length + box2.length;
		boxSum.width = width + box2.width;
		boxSum.breadth = breadth + box2.breadth;
	}

	bool operator == (const Box box2) {
		return ((length == box2.length) && (width == box2.width) && (breadth == box2.breadth));
	}

	bool operator < (const Box box2) {
		double size = length + width + breadth;
		double box2Size = box2.length + box2.width + box2.breadth;
		if (size < box2Size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator > (const Box box2) {
		double size = length + width + breadth;
		double box2Size = box2.length + box2.width + box2.breadth;
		if (size > box2Size) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator = (const Box box2) {
		length = box2.length;
		width = box2.width;
		breadth = box2.breadth;
	}
	
	void print() {
		cout << "length = " << length << " width = " << width << " breadth = " << breadth << endl;
	}
};

int main() {

	Box box(10, 20, 30);
	++box;
	box.print();
}