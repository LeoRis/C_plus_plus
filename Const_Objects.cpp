#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

class Person {

enum {NameLen = 20, AddrLen = 30, PhoneLen = 10};

private:
	char name[NameLen + 1];
	char address[AddrLen + 1];
	char phone[PhoneLen + 1];

public:
	Person(const char* n = "", const char* a = "-unknown-", const char* p = "-unknown-") {
		strncpy(name, n, NameLen);
		strncpy(address, a, AddrLen);
		strncpy(phone, p, PhoneLen);
	}

	void setName(const char* n) {
		strncpy(name, n, NameLen);
		name[NameLen] = 0;
	}
	void setAddress(const char* a) {
		strncpy(address, a, AddrLen);
		address[AddrLen] = 0;
	}
	void setPhone(const char* p) {
		strncpy(phone, p, PhoneLen);
		phone[PhoneLen] = 0;
	}

	const char* getName() const {
		return (name);
	}
	const char* getAddress() const {
		return (address);
	}
	const char* getPhone() const {
		return (phone);
	}

	void Show() const {
		cout << name << " " << address << " " << phone << endl;
	}
};

int main() {
	Person P1("Somebody", "somebody@net.com");
	const Person P2("Other", "other@other.com", "555-1234");

	Person P3;
	const char* p;

	cout << P1.getName() << endl;
	P1.setName("This");
	P1.Show();

	P2.Show();
	cout << P2.getName() << endl;

	P3 = P2;

	p = P2.getPhone();
}