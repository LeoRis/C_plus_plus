#include <iostream>
using namespace std;

class Enemy{
    public:
        virtual void attack();
};

class Ninja : public Enemy{
    public:
        void attack(){
            cout << "Ninja attacks!!" << endl;
        }
};

class Monster : public Enemy{
    public:
        void attack(){
            cout << "Monster attacks!!" << endl;
        }
};

int main(){

    Ninja n;
    Monster m;

    Enemy *enemyN = &n;
    Enemy *enemyM = &m;

    enemyN->attack();
    enemyM->attack();

}
