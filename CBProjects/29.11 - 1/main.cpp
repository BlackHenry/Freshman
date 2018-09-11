#include <iostream>
#include <cmath>
using namespace std;

//Angle given in radii
struct Polar{
    long double angle;
    long double radius;
};

struct Cartitian{
    long double x;
    long double y;
};

void PD(Polar p, Cartitian &d){
    d.x = p.radius * cos(p.angle);
    d.y = p.radius * sin(p.angle);
}

int main()
{
    Polar p;
    Cartitian d;
    long double r, a;
    cin >> p.radius >> p.angle;
    PD(p, d);
    cout << d.x << " " << d.y << endl;
    return 0;
}
