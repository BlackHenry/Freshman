#include <iostream>
#include <cmath>

using namespace std;

double prec = 0.01;
int depth = 0;

double F(double x){
    return x*x*x + 2*x*x - 5*x - 15;
}

double (*f_ptr)(double) = &F;

double root(double a = -10000.0, double b = 10000.0){
    double m = (a + b) / 2.0;

    if(abs(b - a) < prec){
        return m;
    }

    double y = f_ptr(m);
    if(y < 0){
        a = m;
    }
    if(y > 0){
        b = m;
    }
    if(y == 0){
        return m;
    }
    depth++;
    return root(a, b);
}

int main()
{
    cout << root() << " ";
    cout << depth << endl;
    double a = -20.0, b = 20.0, res, y = 10*prec;
    int iter = 0;
    while(abs(y) >= prec){
        double y0 = f_ptr(a), y1 = f_ptr(b);
        double intersect = ((a - b) * y0)/(y1 - y0) + a;
        y = f_ptr(intersect);
        iter++;
        if(y < 0){
            if(abs(a - intersect) < prec){
                res = a;
                break;
            }
            a = intersect;
        }
        if(y > 0){
            if(abs(b - intersect) < prec){
                res = b;
                break;
            }
            b = intersect;
        }
        if(y == 0){
            res = intersect;
            break;
        }
        res = (a + b) / 2.0;
    }
    cout << res << " " << iter << endl;
    return 0;
}
