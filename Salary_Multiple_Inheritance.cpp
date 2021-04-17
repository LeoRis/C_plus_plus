#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	string m_name;
	static float Point;

public:
	Employee(char* name) : m_name(name) {}
	virtual ~Employee() {}

	static void SetPoint(float newPoint) { Point = newPoint; }
	float getPoint(void) const { return Point; }
	const string& name(void) const { return m_name; }
	void ChangeName(const string& newName) { m_name = newName; }
	virtual float Salary(void) const = 0;
	virtual void Show(void) const = 0;
};

class Director : public Employee {
private:
	float Point_Salary;

public:
	Director(char* name, float salary) : Employee(name), Point_Salary(salary) {}
	~Director() {}

	float Salary(void) const { return Point_Salary * getPoint(); }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void Base(float value) { Point_Salary = value; }
};

class Mechanic : public Employee {
private:
	float hour_rate;
	int working_hours;

public:
	Mechanic(char* name, float h_rate, int w_hours) : Employee(name), hour_rate(h_rate), working_hours(w_hours) {}
	~Mechanic() {}

	float Salary(void) const { return hour_rate * working_hours * getPoint(); }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void WorkingHours(int hour) { working_hours = hour; }
	void HourRate(float value) { hour_rate = value; }
};

class Dealer : public Employee {
private:
	float m_bonus;
	int m_sales;

public:
	Dealer(char* name, float commission, int nr_of_sales) : Employee(name), m_bonus(commission), m_sales(nr_of_sales) {}
	~Dealer() {}

	float Salary(void) const { return m_bonus * m_sales * getPoint(); }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void Bonus(float value) { m_bonus = value; }
	void Sales(int number) { m_sales = number; }
};

class Seller : public Dealer {
private:
	float monthly;

public:
	Seller(char* name, float commission, int nr_of_sales, float base) : Dealer(name, commission, nr_of_sales), monthly(base) {}
	~Seller() {}

	float Salary(void) const { return monthly * getPoint(); }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void Base(float value) { monthly = value; }
};

class Freelancer : public Employee {
private:
	float freelance_fee;

public:
	Freelancer(char* name, float fee) : Employee(name), freelance_fee(fee) {}
	~Freelancer() {}

	float Salary(void) const { return freelance_fee; }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void FreelanceFee(float value) { freelance_fee = value; }
};

class Consultant : public Freelancer {
private:
	float bonus;

public:
	Consultant(char* name, float fee, float service) : Freelancer(name, fee), bonus(service) {}
	~Consultant() {}

	float Salary(void) const { return bonus + Freelancer::Salary(); }
	void Show(void) const { cout << name() << ' ' << Salary(); }
	void Bonus(float value) { bonus = value; }
};

float Employee::Point = 10.0;

int main() {

	Employee::SetPoint(12.0);
	Employee* Company[] = {
		new Director("Director Jack", 1000.0),
		new Mechanic("Mechanic Chris", 3.5, 45),
		new Seller("Seller Max", 300.0, 30.0, 5),
		new Seller("Seller Tom", 400.0, 25.0, 3),
		new Dealer("Dealer", 50.0, 3),
		new Freelancer("Freelancer George", 100.0),
		new Consultant("Consultant Adrian", 500.0, 3),
		0
	};

	float total = 0.0;
	Employee* Emp;

	for (int i = 0; Emp = Company[i];i++) {
		Emp->Show();
		cout << endl;
		total += Emp->Salary();
	}

	cout << "Total to be paid: " << total << endl;

	for (int i = 0; Company[i]; delete Company[i++]);

	return 0;

}