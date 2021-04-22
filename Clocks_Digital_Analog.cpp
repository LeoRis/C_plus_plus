#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

#pragma warning(disable : 4996)

using namespace std;

enum format { AM, PM };

class Clock {
protected:
	int m_hour;
	int m_minute;
	int m_second;
	char* m_manufacturer;

public:
	Clock() {}
	Clock(int hour, int minute, int second, const char* manufacturer) {
		m_hour = hour;
		m_minute = minute;
		m_second = second;
		m_manufacturer = new char[strlen(manufacturer)];
		strcpy(m_manufacturer, manufacturer);
	}
	Clock(const Clock& obj) {
		m_hour = obj.m_hour;
		m_minute = obj.m_minute;
		m_second = obj.m_second;
		m_manufacturer = new char[strlen(obj.m_manufacturer)];
		strcpy(m_manufacturer, obj.m_manufacturer);
	}
	virtual ~Clock() { delete[] m_manufacturer; }

	virtual void print_Time() = 0;

	Clock& operator = (const Clock& obj) {
		if (this != &obj) {
			m_hour = obj.m_hour;
			m_minute = obj.m_minute;
			m_second = obj.m_second;
			m_manufacturer = new char[strlen(obj.m_manufacturer)];
			strcpy(m_manufacturer, obj.m_manufacturer);
		}
		return *this;
	}

	int get_Hour() { return m_hour; }
	int get_Minute() { return m_minute; }
	int get_Second() { return m_second; }
	string get_Manufacturer() { return string(m_manufacturer); }

	friend bool operator == (Clock& obj1, Clock& obj2) {
		int first = obj1.get_Second() + obj1.get_Minute() * 60 + obj1.get_Hour() * 3600;
		int second = obj2.get_Second() + obj2.get_Minute() * 60 + obj2.get_Hour() * 3600;
		if (abs(double(first - second)) < 30) {
			return true;
		}
		else {
			return false;
		}
	}

	friend ostream& operator << (ostream& out, const Clock& obj) {
		out << obj.m_manufacturer << ":" << obj.m_hour << ":" << obj.m_minute << ":" << obj.m_second << endl;
		return out;
	}
};

class DigitalClock : public Clock {
private:
	int m_hundreds;
	char m_format;

public:
	DigitalClock() {}
	DigitalClock(int hour, int minute, int second, const char* manufacturer, int hundreds, char format) 
		: Clock(hour, minute, second, manufacturer), m_hundreds(hundreds), m_format(format) {}
	DigitalClock(const DigitalClock& obj) : Clock(obj), m_hundreds(obj.m_hundreds), m_format(obj.m_format) {}
	~DigitalClock() {}

	int get_Hundreds() { return m_hundreds; }
	char get_Format() { return m_format; }

	void print_Time() {
		cout << get_Manufacturer() << " " << get_Hour() << ":" << get_Minute() << ":" << get_Second() << ":" << get_Hundreds();
		if (m_format == AM) {
			cout << " AM";
		}
		else {
			cout << " PM";
		}
	}

	friend ostream& operator << (ostream& out, const DigitalClock& obj) {
		out << obj.m_manufacturer << ":" << obj.m_hour << ":" << obj.m_minute << ":" << obj.m_second << ":" << obj.m_hundreds << " " << obj.m_format << endl;
		return out;
	}
};

class AnalogClock : public Clock {
public:
	AnalogClock() {}
	AnalogClock(int hour, int minute, int second, const char* manufacturer) : Clock(hour, minute, second, manufacturer) {}
	AnalogClock(const DigitalClock& obj) : Clock(obj) {}
	~AnalogClock() {}

	void print_Time() {
		cout << get_Manufacturer() << " " << get_Hour() << ":" << get_Minute() << ":" << get_Second() << endl;
	}

	friend ostream& operator << (ostream& out, const AnalogClock& obj) {
		out << obj.m_manufacturer << ":" << obj.m_hour << ":" << obj.m_minute << ":" << obj.m_second << endl;
		return out;
	}
};

void print(Clock** clock, int number) {
	for (int i = 0; i < number; i++) {
		clock[i]->print_Time();
		cout << endl;
	}
}

int main() {

	Clock** clocks;
	clocks = new Clock * [2];

	// Try changing the seconds to see the effect.
	clocks[0] = new DigitalClock(10, 10, 50, "CASIO", 34, AM);
	clocks[1] = new AnalogClock(10, 10, 10, "HUBLOT");

	cout << "Equality: " << (*clocks[0] == *clocks[1]) << endl;

	print(clocks, 2);

	for (int i = 0; i < 2; i++) {
		delete clocks[i];
	}
	delete[] clocks;

	return 0;
}
