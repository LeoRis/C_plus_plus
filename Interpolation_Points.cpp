#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Point {
private:
	double m_x, m_y;

public:
	Point(){}
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() {}

	virtual void set(double x, double y) { m_x = x; m_y = y; }
	double getX() const { return m_x; }
	double getY() const { return m_y; }

	virtual Point interpolate(const Point& obj) const {
		Point i;
		i.m_x = (m_x + obj.m_x) / 2;
		i.m_y = (m_y + obj.m_y) / 2;
		return i;
	}

	friend ostream& operator << (ostream& out, const Point& pt) {
		return out << "(" << pt.m_x << ", " << pt.m_y << ")";
	}
};

class Point3D : public Point {
private:
	double m_z;

public:
	Point3D(){}
	Point3D(double x, double y, double z) : Point(x, y), m_z(z){}
	~Point3D(){}

	void set(double x, double y, double z) { Point::set(x, y); m_z = z; }
	double getZ() const { return m_z; }

	Point3D interpolate(const Point3D& obj) const {
		Point3D i;
		i.set((getX() + obj.getX()) / 2, (getY() + obj.getY()) / 2, (getZ() + obj.getZ()) / 2);
		return i;
	}

	friend ostream& operator << (ostream& out, const Point3D& obj) {
		return out << "(" << obj.getX() << ", " << obj.getY() << ", " << obj.m_z << ")";
	}
};

class F {
private:
	Point3D* points;
	int max;
	int number;

public:
	F(int m = 0) {
		max = m;
		points = new Point3D[m];
		number = 0;
	}

	F(const F& f) {
		max = f.max;
		number = f.number;
		points = new Point3D[max];
		
		for (int i = 0; i < number; i++) {
			points[i] = f.points[i];
		}
	}

	F operator = (const F& f) {
		if (this != &f) {
			max = f.max;
			number = f.number;
			delete[] points;
			points = new Point3D[max];

			for (int i = 0; i < number; i++) {
				points[i] = f.points[i];
			}
		}
		return *this;
	}

	F operator += (const Point3D& pt) {
		if (number < max) {
			points[number] = pt;
			number++;
		}
		else {
			cout << "No space for a new point!\n";
		}
		return *this;
	}

	Point3D& operator [] (int i) {
		if (i >= 0 && i < number) {
			return points[i];
		}
		else {
			cout << "Invalid index!\n";
		}
		exit(1);
	}

	F interpolate() {
		F f(max * 2 - 1);
		f += points[0];

		for (int i = 0; i < number - 1; i++) {
			f += points[i].interpolate(points[i + 1]);
			f += points[i + 1];
		}
		return f;
	}
	~F() { delete[] points; }

	friend ostream& operator << (ostream& out, const F& obj) {
		for (int i = 0; i < obj.number - 1; i++) {
			out << obj.points[i] << "->";
		}
		return out << obj.points[obj.number - 1];
	}
};

int main() {

	Point3D Point(1, 1, 1);

	F f(5);

	for (int i = 0; i < 3; i++) {
		f += Point;
		Point.set(2 * (i + 1), 2 * (i + 1), 2 * (i + 1));
	}

	cout << f << endl;
	cout << Point << endl;

	F fi;

	fi = f.interpolate();
	cout << fi << endl;

	fi[0] = Point;
	fi += Point;

	cout << fi << endl;
	cout << f[0] << ' ';
	cout << fi[7] << endl;

	return 0;
}