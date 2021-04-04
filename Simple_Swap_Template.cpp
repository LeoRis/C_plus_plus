#include <iostream>

using namespace std;

template<typename T>
//template<class T> -> This works the same.

void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {

	string Name;
	string Surname;

	int Age;
	int YOB;

	cout << "What is your name?" << endl;
	cin >> Name;
	
	cout << "What is your surname?" << endl;
	cin >> Surname;

	cout << "How old are you?" << endl;
	cin >> Age;

	cout << "When were you born?" << endl;
	cin >> YOB;

	cout << "Starting values:" << endl;
	cout << Name << ' ' << Surname << endl;
	cout << Age << ' ' << YOB << endl;

	Swap<string>(Name, Surname);
	Swap<int>(Age, YOB);

	cout << "Swapped values:" << endl;
	cout << Name << ' ' << Surname << endl;
	cout << Age << ' ' << YOB << endl;
}