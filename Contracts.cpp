#include <iostream>
#include <string>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

class Date {
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date(){}
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year){}
	Date(const Date& obj) : m_day(obj.m_day), m_month(obj.m_month), m_year(obj.m_year){}
	~Date(){}

	bool operator < (Date& obj) {
		if (m_year == obj.m_year && m_month < obj.m_month && m_day < obj.m_day) {
			return true;
		}
		else {
			return false;
		}
	}

	friend ostream& operator << (ostream& out, const Date& obj) {
		return out << obj.m_day << "." << obj.m_month << "." << obj.m_year << endl;
	}
};

class Contract {
private:
	int contract_number;
	char contract_category[50];
	char** contract_signers;
	int number_of_signers;
	Date date;

public:
	Contract(){}
	Contract(int cNumber, const char* cCat, const char* cSign, int nSigners, Date& _date) {
		contract_number = cNumber;
		strncpy(contract_category, cCat, 49);
		contract_category[19] = '\0';
		contract_signers = new char*[nSigners];
		strncpy(*contract_signers, cSign, 20);
		number_of_signers = nSigners;
		for (int i = 0; i < number_of_signers; i++) {
			contract_signers[i] = new char[20];
			strcpy(contract_signers[i], contract_signers[i]);
		}
		date, _date;
	}
	Contract(const Contract& obj) {
		contract_number = obj.contract_number;
		strcpy(contract_category, obj.contract_category);
		contract_signers = new char*[obj.number_of_signers];
		number_of_signers = obj.number_of_signers;
		for (int i = 0; i < number_of_signers; i++) {
			contract_signers[i] = new char[20];
		}
		date = obj.date;
	}
	Contract& operator = (const Contract& obj) {
		if (this != &obj) {
			contract_number = obj.contract_number;
			strcpy(contract_category, obj.contract_category);
			for (int i = 0; i < number_of_signers; i++) {
				delete[] contract_signers[i];
			}
			delete[] contract_signers;
			number_of_signers = obj.number_of_signers;
			contract_signers = new char* [obj.number_of_signers];
			for (int i = 0; i < number_of_signers; i++) {
				contract_signers[i] = new char[20];
				strcpy(contract_signers[i], obj.contract_signers[i]);
			}
			date = obj.date;
		}
		return *this;
	}
	~Contract() {
		for (int i = 0; i < number_of_signers; i++) {
			delete[] contract_signers[i];
		}
		delete[] contract_signers; 
	}

	void set_Contract_Number(int cNumber) { contract_number = cNumber; }
	void set_Contract_Category(char* cCat) { strncpy(contract_category, cCat, 49); contract_category[49] = '\0';}
	void set_Number_Of_Signers(int nSigners) { number_of_signers = nSigners; }
	void set_Contract_Signers(char** cSign, int nSigners) {
		for (int i = 0; i < number_of_signers; i++) {
			delete[] contract_signers[i];
		}
		delete[] contract_signers;
		number_of_signers = nSigners;
		contract_signers = new char* [nSigners];
		for (int i = 0; i < number_of_signers; i++) {
			contract_signers[i] = new char[20];
			strcpy(contract_signers[i], cSign[i]);
		}
	}
	void set_Date(Date _date) { date = _date; }

	int get_Contract_Number() { return contract_number; }
	const char* get_Contract_Category() { return contract_category; }
	int get_Number_Of_Signers() { return number_of_signers; }
	const char* const* get_Contract_Signers() { return contract_signers; }
	Date get_Date() { return date; }

	friend ostream& operator << (ostream& out, const Contract& obj) {
		out << "Contract number: " << obj.contract_number;
		out << "Contract category: " << obj.contract_category;
		out << "Contract signers: " << endl;
		for (int i = 0; i < obj.number_of_signers; i++) {
			out << obj.contract_signers[i] << endl;
		}
		out << "Date: " << endl;
		out << obj.date << endl;
		return out;
	}
};

class Contract_Cluster {
private:
	Contract* contracts;
	int number_of_contract_objects;

public:
	Contract_Cluster(){}
	Contract_Cluster(Contract* _contracts, int cObjects) {
		number_of_contract_objects = cObjects;
		contracts = new Contract[number_of_contract_objects];
		for (int i = 0; i < number_of_contract_objects; i++) {
			contracts[i] = _contracts[i];
		}
	}
	Contract_Cluster(const Contract_Cluster& obj) {
		number_of_contract_objects = obj.number_of_contract_objects;
		contracts = new Contract[obj.number_of_contract_objects];
		for (int i = 0; i < number_of_contract_objects; i++) {
			contracts[i] = obj.contracts[i];
		}
	}
	Contract_Cluster& operator = (const Contract_Cluster& obj) {
		if (this != &obj) {
			delete[] contracts;
			number_of_contract_objects = obj.number_of_contract_objects;
			contracts = new Contract[obj.number_of_contract_objects];
			for (int i = 0; i < number_of_contract_objects; i++) {
				contracts[i] = obj.contracts[i];
			}
		}
		return *this;
	}
	~Contract_Cluster() { delete[] contracts; }

	Contract_Cluster& operator += (Contract& obj) {
		Contract* temp = new Contract[number_of_contract_objects + 1];
		for (int i = 0; i < number_of_contract_objects; i++) {
			temp[i] = contracts[i];
		}
		delete[] contracts;
		contracts = temp;
		contracts[number_of_contract_objects] = obj;
		number_of_contract_objects++;
		return *this;
	}

	Contract_Cluster signed_Contracts(Date& date) {
		Contract_Cluster temp;
		for (int i = 0; i < number_of_contract_objects; i++) {
			if (!(contracts[i].get_Date() < date) && !(date < contracts[i].get_Date())) {
				temp += contracts[i];
			}
		}
		return temp;
	}

	friend ostream& operator << (ostream& out, const Contract_Cluster& obj) {
		out << "Cluster of contracts: " << endl;
		out << "Contracts: " << endl;
		for (int i = 0; i < obj.number_of_contract_objects; i++) {
			out << obj.contracts[i] << endl;
		}
		return out;
	}
};

int main() {

	char* signers[3] = { "aaa", "bbb", "ccc" };
	Contract d1(10, "Cat1", signers, 3, Date(10, 10, 2020));
	Contract d2(11, "Cat2", signers, 2, Date(11, 11, 2021));

	cout << d1;
	cout << d2;

	Contract* con;
	con = new Contract[2];
	con[0] = d1;
	con[1] = d2;

	Contract_Cluster kls(con, 2);
	Contract d3(15, "Cat3", 0, 0, Date(12, 12, 2021));
	kls += d3;

	Date date(9, 9, 2010);
	cout << endl;
	cout << kls.signed_Contracts(date) << endl;
	
	delete[] con;

	return 0;
}