#include <iostream>
#include <string>

using namespace std;

class friendClass{
public:
    friendClass(){friendVar = 0;}
private:
    int friendVar;

    friend void functionFriend(friendClass &fo);
};

void functionFriend(friendClass &fo){
    fo.friendVar = 99;
    cout << fo.friendVar << endl;
}

int main(){

    friendClass friendObject;

    functionFriend(friendObject);

}
