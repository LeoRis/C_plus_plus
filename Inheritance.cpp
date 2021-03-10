#include <iostream>
using namespace std;

class Mother{
public:
    void sayName();
};

void Mother::sayName(){
    cout << "Inheritance" << endl;
}

class Daughter : public Mother{
public:

};

int main(){

    Daughter name;

    name.sayName();

}
