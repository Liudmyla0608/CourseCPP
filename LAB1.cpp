#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double b = 1.5, ha = -0.1, E = 0.001, hx = 0.21, z;
    for(double x = 0.5; x <= 3.1; x += hx) {
        for(double a = -0.1; a >= -1.4; a += ha) {
            if (x < b)
                z = sin(fabs(a * x + pow(b, a)));
            else
                z = cos(fabs(a * x - pow(b, a)));
            cout << "z=\t" << z << endl;
        }
    }
}
