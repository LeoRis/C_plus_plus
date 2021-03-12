#include <iostream>
using namespace std;

template <class T>
class notCharacters{
    public:
        notCharacters(T x){
            cout << x << " is not a character!" << endl;
        }
};

template<>
class notCharacters<char>{
    public:
        notCharacters(char c){
            cout << c << " is definitely a character!" << endl;
        }
};

int main(){

    notCharacters<int> object1(4);
    notCharacters<double> object2(4.15);
    notCharacters<char> object3('q');

}
