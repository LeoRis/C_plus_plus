#include <iostream>

using namespace std;

class MyClass{
public:
    int who;
    MyClass(int id);
    ~MyClass();
} glob_ob1(1), glob_ob2(2);

MyClass::MyClass(int id){
    cout << "Initialization " << id << "\n";
    who = id;
}

MyClass::~MyClass(){
    cout << "Destruction " << who << "\n";
}

int main(){
    MyClass local_ob1(3);
    cout << "This is not the first message on the screen.\n";

    MyClass local_ob2(4);
    return 0;
}
