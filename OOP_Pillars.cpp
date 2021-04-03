#include <iostream>

using namespace std;

class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
	string Company;
	int Age;

protected:
	string Name;

public:
	Employee(string name, string company, int age) : Name(name), Company(company), Age(age) {
		//Name = name;
		//Company = company;
		//Age = age;
	}

	void setName(string name){
		Name = name;
	}

	string getName() {
		return Name;
	}

	void setCompany(string company) {
		Company = company;
	}

	string getCompany() {
		return Company;
	}

	void setAge(int age) {
		Age = age;
	}

	int getAge() {
		return Age;
	}

	void IntroduceYourself() {
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}

	void AskForPromotion() {
		if (Age > 30) {
			cout << Name << " got promoted!" << endl;
		}
		else {
			cout << Name << ", sorry NO promotion for you!" << endl;
		}
	}

	virtual void Work() {
		cout << Name << " is checking email, task backlog, performing tasks..." << endl;
	}
};

class Developer : public Employee {
public:
	string FavProgrammingLanguage;

	Developer(string name, string company, int age, string favProgrammingLanguage)
		: Employee(name, company, age), FavProgrammingLanguage(favProgrammingLanguage){
		//FavProgrammingLanguage = favProgrammingLanguage;
	}

	void fixBug() {
		cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
	}

	void Work() {
		cout << Name << " is developing great software!" << endl;
	}

};

class Teacher : public Employee {
public:
	string Subject;

	Teacher(string name, string company, int age, string subject)
		: Employee(name, company, age), Subject(subject) {
		//Subject = subject; 
	}

	void PrepareLesson() {
		cout << Name << " is preparing " << Subject << " lesson" << endl;
	}

	void Work() {
		cout << Name << " is teaching cool science!" << endl;
	}

};

int main() {
	Developer dev("Jack", "Tesla", 35, "C++");
	Teacher teach("Jane", "MIT", 57, "Science");

	dev.Work();
	teach.Work();

	Employee* emp1 = &dev;
	Employee* emp2 = &teach;

	emp1->Work();
	emp2->Work();
}