#include <iostream>
#include <math.h>

using namespace std;

class Triangle{

public:
    Triangle(int x, int y, int z){
        a = x;
        b = y;
        c = z;
    };
    ~Triangle(){};

    float area(){
        float s = (a + b + c) / 2;
        float p = sqrt(s * (s - a) * (s - b) * (s - c));
        return p;
    }

    int perimeter(){
        return a + b + c;
    }

private:
    int a, b, c;

};

int main(){

    int sideA, sideB, sideC;

    cin >> sideA >> sideB >> sideC;

    Triangle t(sideA, sideB, sideC);

    if(sideA + sideB <= sideC || sideB + sideC <= sideA || sideA + sideC <= sideB){
        cout << "This is an impossible triangle." << endl;
    }else{
        cout << "The area of the triangle t is: " << t.area() << endl;
        cout << "The perimeter of the triangle t is: " << t.perimeter() << endl;
    }

    return 0;
}
