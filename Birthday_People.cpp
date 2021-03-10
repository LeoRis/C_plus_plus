#include <iostream>
#include <string>

using namespace std;

class Birthday{
public:
    Birthday(int m, int d, int y);
    void printDate();

private:
    int month;
    int day;
    int year;
};

class People{
public:
    People(string x, Birthday bo);
    void printInfo();

private:
    string name;
    Birthday dateOfBirth;
};

Birthday::Birthday(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Birthday::printDate(){
    cout << month << "/" << day << "/" << year << endl;
}

People::People(string x, Birthday bo)
: name(x), dateOfBirth(bo)
{

}

void People::printInfo(){
    cout << name << " was born on ";
    dateOfBirth.printDate();
}

int main(){

    Birthday birthObj(1, 1, 1990);

    People johnDoe("Lynx", birthObj);
    johnDoe.printInfo();
}
