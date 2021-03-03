#include <iostream>
#include <cmath>

using namespace std;

namespace RAD{
    double angle;
    double sine(double x){
        return (std::sin(x));
    }
}

namespace DEG{
    int angle;
    double sine(int x){
        return (std::sin(x * M_PI / 180));
    }
}

int main(){

    float angleRad;
    cout << "What is the angle for the radian?" << endl;
    cin >> angleRad;

    int angleDeg;
    cout << "What is the angle for the degree?" << endl;
    cin >> angleDeg;

    {
        using namespace RAD;
        cout << " sine(" << angleRad << "rad) = " << sine(angleRad) << endl;
    }

    {
        using namespace DEG;
        cout << " sine(" << angleDeg << "deg) = " << sine(angleDeg) << endl;
    }

    return 0;

}
