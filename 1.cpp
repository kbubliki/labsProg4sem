#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;
const double PI = 3.14159265;
int main(int argc, const char * argv[]) {//Вариант 24
    /////////////////////////////////////////////////////////
    double c = 0.004, alfa = 10, p = 0.88, v = 220, s = 20;//вставить свои значения
    double der_c = 0.001, der_alfa = 0.01, der_p = 0.01, der_v = 0.01, der_s = 0.04;//вставить свои значения
    double func = 0;
    func = c * alfa * p * (v * v) * s;
    double der_func = 0;
    der_func = der_c + der_alfa + der_p + 2*der_v + der_s;
    double delta_func = 0;
    delta_func = der_func * func;
    cout << func << endl << delta_func << endl /**<< setprecision(1)*/<< der_func << endl ;
    /////////////////////////////////////////////////////////
    
    double a = 0.28, b = 10.536;//вставить свои значения
    double delta_a = 0.006, delta_b = 0.002;//вставить свои значения
    int i =0;
    cout << "Введите номер варинта значений: 1 - 3\n";
    cin >> i;
    switch (i) {
        case 1:
            a = 0.44, b = 9.542;//вставить свои значения
            delta_a = 0.03, delta_b = 0.001;//вставить свои значения
            break;
        case 2:
            a = 0.772, b = 4.218;//вставить свои значения
            delta_a = 0.0005, delta_b = 0.001;//вставить свои значения
            break;
        case 3:
            a = 1.49, b = 29.725;//вставить свои значения
            delta_a = 0.01, delta_b = 0.0005;//вставить свои значения
            break;
        default:
            break;
    }
    double der_a = 0, der_b = 0;
    der_a = fabs(delta_a) / fabs(a);
    der_b = fabs(delta_b) / fabs(b);
    double y = 0;
    y = ln(sin(3*a))/(6*b-PI)^2;//вставить свою функцию
    double der_y = 0;
    double v1 = 0, v2 = 0;
    v1 = (3*cos(3*a))/(((6*b-PI)^2)*sin(3*a));//посчитать частную производную по 1 аргументу от своей функции в wolfram
    v2 = (-12*ln(sin(3*a)))/(6*b-PI)^3;//посчитать частную производную по 1 аргументу от своей функции в wolfram
    der_y =v1 * der_a + v2 *der_b;
    double delta_y = 0;
    delta_y = der_y * fabs(y);
    cout << y << endl << delta_y << endl  << der_y << endl;
    return 0;
}
