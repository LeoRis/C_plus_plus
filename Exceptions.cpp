#include <iostream>
using namespace std;

int main(){

    try{
        int momAge;
        cout << "Enter mom's age: " << endl;
        cin >> momAge;

        int sonAge;
        cout << "Enter son's age: " << endl;
        cin >> sonAge;

        if(sonAge > momAge){
            throw 99;
        }
    }catch(int x){
        cout << "Son can't be older than mom, ERROR NUMBER: " << x << endl;
    }

}
