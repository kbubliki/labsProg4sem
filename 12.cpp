#include <iostream>

#include "math.h"

#include <iomanip>//для управление выводом (ф-ии setprecision(4))

double fx0 (double x);

double fx1 (double x);

double ft1 (double t);

double ft2 (double t);

double *progonka (double *a, double *b, double *c, double *d);

void setka( double *a,double *b,double *c,int m, double **u);

double fun(int i,int j,double **u);

int main(int argc, const char * argv[]) {

int n = 11;

int m = 6;

double h = 0.2;

double **u = new double *[m + 1];

for (int i = 0; i < m + 1; i++)

{

u[i] = new double[n + 1];

}

double *x = new double [n + 1];

double *v = new double [n + 1];

for (int i = 1; i <= n; i++) {

x[i] = (i-1)*h;

u[1][i] = fx0(x[i]);

v[i] = fx1(x[i]);

}

double *t = new double [m + 1];

for (int j = 1; j <= m; j++) {

t[j] = (j-1)*h;

u[j][1] = ft1(t[j]);

u[j][n] = ft2(t[j]);

}

for (int i = 2; i <= n-1; i++) {

u[2][i] = u[1][i]+h*v[i];

}

double *b = new double [10];

double *a = new double [10];

double *c = new double [10];

for (int i = 1; i <= 9; i++) {

b[i] = 3;

a[i] = 1;

c[i] = 1;

}

a[1] = 0;

c[9] = 0;

setka(a,b,c,m, u);

return 0;

}

double fx0 (double x) {

return (x+0.5)*(x+0.5);

}

double fx1 (double x) {

return (x+1)*sin(x);

}

double ft1 (double t) {

return 0.5*(0.5+t);

}

double ft2 (double t) {

return 6.25;

}

double fun(int i,int j,double **u) {

return u[j-1][i] - 2*u[j][i];

}

void setka(double *a,double *b,double *c,int m, double **u) {

double *f= new double[10];

double *xx = new double[10];

int n = 9 + 2;//rows(b)+2

for (int j = 2; j <= m-1; j++) {

for (int i = 2; i <=n-1; i++) {

f[i-1]=fun(i,j,u);

}

xx = progonka(a,b,c,f);

for (int i = 2; i <= n-1; i++) {

u[j+1][i] = xx[i-1];

}

}

//вывод таблицы

std::cout << std::setprecision(3);

for (int i = 1; i <= m; i++) {

for (int j = 1; j <= n; j++) {

std::cout << u[i][j] << "\t";

}

std::cout << std::endl;

}

}

double *progonka (double *a, double *b, double *c, double *d) {

double *gamma = new double [10];

double *beta = new double [10];

double *alfa = new double [10];

double *x = new double [10];

gamma[1] = b[1];

beta[1] = d[1]/gamma[1];

alfa[1] = (-c[1])/gamma[1];

int n = 9;//rows(b)

for (int i = 2; i <= n-1; i++) {

gamma[i] = b[i] + a[i]*alfa[i-1];

alfa[i] = (-c[i])/gamma[i];

beta[i] = (d[i] - a[i]*beta[i-1])/gamma[i];

}

gamma[n] = b[n]+a[n]*alfa[n-1];

beta[n] = (d[n] - a[n]*beta[n-1])/gamma[n];

x[n] = beta[n];

for (int i = n-1; i >= 1; i--) {

x[i] = alfa[i]*x[i+1]+beta[i];

}

return x;

} 