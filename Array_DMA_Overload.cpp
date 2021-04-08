#include <iostream>

using namespace std;

class Array {
private:
	int m_size;  // How many elements the array could have
	int m_count; // How many elements the array has
	int* elem;   // Pointer to the array

public:
	Array(int size = 10) : m_size(size), m_count(0), elem(new int[size]){}
	Array(const Array& obj) : m_size(obj.m_size), m_count(obj.m_count), elem(new int[m_size]){
		for (int i = 0; i < m_count; i++) {
			elem[i] = obj.elem[i];
		}
	}
	Array& operator = (const Array& obj) { // To prevent self-assignment
		if (this != &obj) {
			m_size = obj.m_size;
			m_count = obj.m_count;
			for (int i = 0; i < m_count; i++) {
				elem[i] = obj.elem[i];
			}
		}
		return *this;
	}
	Array& operator += (int element) {
		if (m_count < m_size) {		// If still space available, add the next element
			elem[m_count++] = element;
		}
		else {						// If capacity is full
			int* temp = new int[m_size * 2]; // Allocate double more memory
				for (int i = 0; i < m_count; i++) {
					temp[i] = elem[i];
				}
				temp[m_count++] = element;
				m_size *= 2;
				delete[] elem;
				elem = temp;
		}
		return *this;
	}
	~Array() { delete[] elem; }

	int& operator [] (int index) {
		if (index >= 0 && index < m_count) {
			return elem[index];
		}
		else {
			cout << "Out of range" << endl;
			exit(-1);
		}
	}

	int GetCapacity() {
		return m_size;
	}

	int GetCount() {
		return m_count;
	}
};


int main() {
	Array Field;
	int n, temp;

	cout << "How many elements will you enter?" << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		Field += temp;
	}

	for (int i = 0; i < Field.GetCount(); i++) {
		cout << Field[i] << "\t";
	}

	cout << endl << Field.GetCapacity();

	return 0;

}