#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	double m_x, m_y;

public:

	Point(double x = 0, double y = 0) : m_x(x), m_y(y){}
	~Point(){}

	double distance(const Point& p) { return sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y)); }
	void move(double x, double y) { m_x += x; m_y += y; }
	friend ostream& operator << (ostream& out, Point& obj) {
		return out << "(" << obj.m_x << ", " << obj.m_x << ")" << endl;
	}
};

class Polygon : public Point {
private:
	Point* points;
	int number;

public:
	Polygon() {
		number = 0;
		points = new Point[number];
	}
	Polygon(Point* p, int m) {
		number = m;
		points = new Point[m];
		for (int i = 0; i < number; i++) {
			points[i] = p[i];
		}
	}
	Polygon(const Polygon& obj) {
		number = obj.number;
		points = new Point[number];
		for (int i = 0; i < number; i++) {
			points[i] = obj.points[i];
		}
	}
	Polygon operator = (const Polygon& obj) {
		if (this == &obj) {
			return *this;
		}
		else {
			number = obj.number;
			delete[] points;
			points = new Point[number];
			for (int i = 0; i < number; i++) {
				points[i] = obj.points[i];
			}
		}
		return *this;
	}

	void move(double dx, double dy) {
		for (int i = 0; i < number; i++) {
			points[i].move(dx, dy);
		}
	}

	double perimeter() const {
		double L = 0;
		for (int i = 0; i < number; i++) {
			L += points[i].distance(points[i + 1]);
		}
		L += points[0].distance(points[number - 1]);
		return L;
	}
	~Polygon() { delete[] points; }

	bool operator == (const Polygon& obj) {
		return (perimeter() == obj.perimeter());
	}
	bool operator != (const Polygon& obj) {
		return (perimeter() != obj.perimeter());
	}
	bool operator < (const Polygon& obj) {
		return (perimeter() < obj.perimeter());
	}
	bool operator >= (const Polygon& obj) {
		return (perimeter() >= obj.perimeter());
	}
	friend ostream& operator << (ostream& out, const Polygon& obj) {
		for (int i = 0; i < obj.number; i++) {
			out << "->" << obj.points[i];
		}
		return out;
	}
};


int main() {

	Point p[5] = { Point(1, 2), Point(4, 1), Point(4, 4), Point(1, 4) };

	Polygon rectangle(p, 4), p2;

	cout << rectangle << endl;
	cout << rectangle.perimeter() << endl;

	p2 = rectangle;
	p2.move(2, 2);

	cout << p2 << endl;
	cout << (rectangle == p2 ? "yes" : "no") << endl;


	return 0;
}