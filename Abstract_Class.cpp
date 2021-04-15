#include <iostream>

using namespace std;

class Shape {
public:
	virtual void Draw() const = 0; // Pure virtual function
	virtual ~Shape(){}
};

class Circle : public Shape {
private:
	float m_x;
	float m_y;
	float m_z;

public:
	Circle(float x, float y, float z) : m_x(x), m_y(y), m_z(z){}
	void Draw() const {		// Must override the pure virtual function
		cout << "Drawing Circle (" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
	}
};

class Rectangle : public Shape {
private:
	float m_x;
	float m_y;
	float m_w;
	float m_h;

public:
	Rectangle(float x, float y, float w, float h) : m_x(x), m_y(y), m_w(w), m_h(h) {}
	void Draw() const {		// Must override the pure virtual function
		cout << "Drawing Rectangle (" << m_x << ", " << m_y << ", " << m_w << ", " << m_h << ")" << endl;
	}
};

int main() {

	//Shape s;	// You can't declare an object from an abstract class!
	Shape* p;	// You can declare a pointer
	Shape* s1[] = { new Circle(1, 2, 3), new Rectangle(2, 3, 4, 5), new Circle(0, 0, 1), 0 };

	int i = 0;

	while (p = s1[i++]) {
		p->Draw();
	}

	for (int i = 0; s1[i]; delete s1[i++]);

	return 0;
}