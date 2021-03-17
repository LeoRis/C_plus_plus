#include <iostream>
#include <string.h>

using namespace std;
enum workPosition{clerk, manager, director};

const int MAX = 100; // Maximum number of emoployees

class EmployeeData{
private:
    char name[MAX];
    float salary;
    workPosition WP;

public:
    EmployeeData(){}

    EmployeeData(char *x, float s, workPosition work){
        strcpy(name, x);
        salary = s;
        WP = work;
    }

    ~EmployeeData(){}

    void setName(char const *n){
        strcpy(name, n);
    }

    void setSalary(int s){
        salary = s;
    }

    void setPosition(workPosition work){
        WP = work;
    }

    char const *getName(void){
        return name;
    }

    int const getSalary(void){
        return salary;
    }

    workPosition const getPosition(void){
        return WP;
    }

};

void Sort(EmployeeData a[], int n);

int main(){

    EmployeeData Employees[MAX];

    float salary;
    int n, WP;
    char name[MAX];

    cout << "Enter number of employees: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Name: ";
        cin >> name;

        cout << "Salary: ";
        cin >> salary;

        cout << "Working Position (WP): ";
        cin >> WP;

        Employees[i].setName(name);
        Employees[i].setSalary(salary);
        Employees[i].setPosition((workPosition)WP);

    }
    Sort(Employees, n);

    for(int i = 0; i < n; i++){

        cout << i + 1 << ". " << Employees[i].getName() << "\t" << Employees[i].getSalary() << "\t" << Employees[i].getPosition() << endl;
    }

    return 0;
}

void Sort(EmployeeData a[], int n){

    EmployeeData p;

    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(a[i].getSalary() < a[j].getSalary()){
                p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
        }
    }
}
