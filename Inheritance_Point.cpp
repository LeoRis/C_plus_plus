#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Point {
private:
	float m_x, m_y;

public:
	Point(float x, float y) : m_x(x), m_y(y){}

	void set(float x, float y) { m_x = x; m_y = y; }
	float get_x() const { return m_x; }
	float get_y() const { return m_y; }

	void Move(float dx, float dy) { m_x += dx; m_y += dy; }
};

class Circle : public Point {
private:
	float m_r;

public:
	void set_r(float r) { m_r = (r > 0) ? r : 0.0; }
	Circle(float x, float y, float r) : Point(x, y), m_r(r) { set_r(r); }
	Circle(const Point& p, float r) : Point(p) { set_r(r); }

	void set(float x, float y, float r) {
		Point::set(x, y);
		set_r(r);
	}
	float get_r() const { return m_r; }
	float Area() const { return m_r * m_r * M_PI; }
};

class Square : public Point {
private:
	float m_a;

public:
	void set_a(float a) { m_a = (a > 0) ? a : 0.0; }
	Square(float x, float y, float a) : Point(x, y), m_a(a) { set_a(a); }
	Square(const Point& p, float a) : Point(p) { set_a(a); }

	void set(float x, float y, float a) {
		Point::set(x, y);
		set_a(a);
	}
	float get_a() const { return m_a; }
	float Area() const { return m_a * m_a; }
};

class Rectangle : public Square {
private:
	float m_b;

public:
	void set_b(float b) { m_b = (b > 0) ? b : 0.0; }
	Rectangle(float x, float y, float a, float b) : Square(x, y, a), m_b(b) { set_b(b); }
	Rectangle(const Point& p, float a, float b) : Square(p, a) { set_b(b); }

	void set(float x, float y, float a, float b) {
		Square::set(x, y, a);
		set_b(b);
	}
	float Area() const { return get_a() * m_b; }
};

int main() {
	Point x(1, 2);
	Square s(x, 1);
	Circle c(3, 4, 2);
	s.set_a(2);

	cout << "Square(" << s.get_x() << "," << s.get_y() << ") : area = " << s.Area() << endl;
	cout << "Circle(" << c.get_x() << "," << c.get_y() << ") : area = " << c.Area() << endl;

	c.Move(3, 4);

	cout << "Circle(" << c.get_x() << "," << c.get_y() << ") : area = " << c.Area() << endl;

	Rectangle r(Point(2, 3), 2, 3);
	cout << "Rectangle(" << r.get_x() << "," << r.get_y() << ") : area = " << r.Area() << endl;

	return 0;
}