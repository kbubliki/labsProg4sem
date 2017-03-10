// lab work 5.1.cpp: определяет точку входа для консольного приложения.
//

#include <math.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double f(double x)
{
//здесь функция, производную которой нужно найти
return sin(x)*exp(cos(x)); //
}

double interal(double a, double b, int n) {
double h = (b-a)/n;
double x[n], f1[n], f2[n+1];
double summf1 = 0, summf2 = 0;
for (int i=1; i<=n; i++){
x[i] = a+h*(i-1);
f2[i] = f(x[i]);
f1[i] = f(x[i]+(h/2));
}
f2[n+1] = f(b);
for (int i=1; i<=n; i++) {
summf1 = summf1 + f1[i];
summf2 = summf2 +f2[i];
}
summf2 = summf2 + f2[n+1];
double I = (h/6)*(f2[1]+f2[n+1]+4*summf1+2*summf2);
return I;
}

int main()
{
setlocale(0, "Rus");
double x, h, fl, fr, fc, f2;
const double PI = 3.14159265;

x = 1; // точка, в которой вычисляем производную
h = PI/20; //

// приближенно вычисляем первую производную различными способами
fl = (f(x) - f(x - h)) / h; // левая
fr = (f(x + h) - f(x)) / h; // правая
fc = (f(x + h) - f(x - h)) / (2 * h); // центральная

// приближенно вычисляем вторую производную
f2 = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);

// выводим результаты на экран
cout << "x = " << x << endl;
cout << "Левая производная fl = " << fl << endl;
cout << "Правая производная fr = " << fr << endl << endl;



double p; // Точная производная
p = cos(x)*exp(cos(x)) - (sin(x))*(sin(x))*exp(cos(x)); // -
cout << "Точная первая производная = " << p << endl;
cout << "Центральная разностная производная fc = " << fc << endl << endl;

double p2;
p2 = (sin(x))*exp(cos(x))*(-1-3*cos(x)+(sin(x))*(sin(x))); // -
cout << "Точная вторая производная = " << p2 << endl;
cout << "Вторая разностная производная = " << f2 << endl << endl;

double in;
in = interal(0, PI/2,2);
cout << "Значение интеграла функции = " << in << endl;

/*double fl, fr, fc;
double x = 1.57075;
double h1 = 0.157075;
double h2 = 0.06283;

double p, p1, p2;
p = (sin(x))*exp(cos(x));
p1 = (sin(x+h1))*exp(cos(x+h1));
p2 = (sin(x-h1))*exp(cos(x-h1));

fl = (p - p2) / h1;
fr = (p1 - p) / h1;

cout << "Левая производная = " << fl << endl;
cout << "Правая производная = " << fr << endl;*/

system("pause");
return (0);
}