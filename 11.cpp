#include <iostream>

#include "math.h"

#include <iomanip>//для управление выводом (ф-ии setprecision(4))

void dirichlet (double a,double b,double c,double d, int n, double eps);

void iteratio (double **u, double eps);

double ff1 (double y);

double ff2 (double y);

double ff3 (double x);

double ff4 (double x);

int main(int argc, const char * argv[]) {

dirichlet(0,1,0,1,11,pow(10, -6));

return 0;

}

double ff1 (double y) {// в комментах 24 вар

return y*y;//-6*y*y - 4*y + 2;

}

double ff2 (double y) {

return cos(y) + y*(3-cos(1)) ;//-6*y*y - 18*y + 10;

}

double ff3 (double x) {

return x*x*x;//5*x*x + 3*x + 2;

}

double ff4 (double x) {

return 2*x + 1;//5*x*x - 11*x - 8;

}

void dirichlet (double a,double b,double c,double d, int n, double eps) {

double l1 = b - a;//1

double l2 = d - c;//1

double h = l1/(n - 1);//0.1

int m = l2/h + 1;//11

double **u = new double *[n + 1];//n + 1 костыль

for (int i = 0; i < n + 1; i++)

{

u[i] = new double[m + 1];// m + 1 тоже

}

double x[n + 1];

for (int i = 1; i <= n; i++) {

x[i] = (i - 1) * h;

u[i][1] = ff3(x[i]);

u[i][n] = ff4(x[i]);

}

double y[m + 1];

for (int j = 1; j <= m; j++) {

y[j] = (j - 1) * h;

u[1][j] = ff1(y[j]);

u[m][j] = ff2(y[j]);

}

double q = 0;//x

for (int i = 2; i <= n - 1; i++) {

for (int j = 2; j <= m - 1; j++) {

q = h * (u[n][j] - u[1][j]);

u[i][j] = u[1][j] + (i -1) * q;

}

}

iteratio(u, eps);

//вывод таблицы

std::cout << std::setprecision(4);//кол-во знаков после точки

for (int i = 1; i <= n; i++) {

for (int j = 1; j <= m; j++) {

std::cout << u[i][j] << "\t";

}

std::cout << std::endl;

}

}

void iteratio (double **u, double eps) {

int n = 11;//rows(u)

int m = 11;//cols(u)

double r2 = pow(10,10);

double te = 0;

int k = 0;

double x = 0;

double r1 = 0;

double r = 0;

while (r2 > te) {

r1 = r2;

r2 = 0;

for (int i = 2; i <=n - 1; i++) {

for (int j = 2; j <= m - 1; j++) {

x = (u[i][j+1]+u[i][j-1]+u[i+1][j]+u[i-1][j])/4;

r = fabs(x - u[i][j]);

if (r2 <= r) {

r2 = r;

}

u[i][j] = x;

}

}

te = eps + (1 - r2/r1);

k++;

if (k > 1000) {

break;

}

}

} 