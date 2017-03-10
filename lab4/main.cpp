#include <iostream>
#include <cstdlib>
#include "var.h"

using namespace std;

int main(int argc, char const *argv[])
{

	// FILLING THE VECTOR X[]
	float *a = new float(0.1);
	float n = 4;
	for (int i = 0; i<20; i++) {
		x[i] = *a;
		*a += 0.2;
	}
	delete a;

	for (int i=0; i<20; i++) {
		x2[i] = x[i] * x[i];
		x3[i] = x2[i] * x[i];
		x4[i] = x3[i];
		xy[i] = x[i] * y[i];
		x2y[i] = x2[i] * y[i];
		sum_x += x[i];
		sum_x2 += x2[i];
		sum_x3 += x3[i];
		sum_x4 += x4[i];
		sum_xy += xy[i];
		sum_x2y += x2y[i];
		sum_y += y[i];
	} 

	cout << "\nModel:\n" << n+1 << "*a0 + " << sum_x << "*a1 + " << sum_x2 << "*a2 = " << sum_y << "\n"
					  << sum_x << "*a0 + " << sum_x2 << "*a1 + " << sum_x3 << "*a2 = " << sum_xy << "\n"
					  << sum_x2 << "*a0 + " << sum_x3 << "*a1 + " << sum_x4 << "*a2 = " << sum_x2y << "\n";

	float mm[3][3];
	mm[0][0] = n+1;
	mm[0][1] = mm[1][0] = sum_x;
	mm[0][2] = mm[1][1] = mm[2][0] = sum_x2;
	mm[1][2] = mm[2][1] = sum_x3;
	mm[2][2] = sum_x4;

	float dd[3] = {sum_y, sum_xy, sum_x2y};

	float main_det = mm[0][0] * mm[1][1] * mm[2][2] + mm[0][1] * mm[1][2] * mm[2][0] + mm[1][0] * mm[2][1] * mm[0][2] 
				   - mm[2][0] * mm[1][1] * mm[0][2] - mm[2][1] * mm[1][2] * mm[0][0] - mm[1][0] * mm[0][1] * mm[2][2];

	float det0 = dd[0] * mm[1][1] * mm[2][2] + mm[0][1] * mm[1][2] * dd[2] + dd[1] * mm[2][1] * mm[0][2] 
				   - dd[2] * mm[1][1] * mm[0][2] - mm[2][1] * mm[1][2] * dd[0] - dd[1] * mm[0][1] * mm[2][2];

	float det1 = mm[0][0] * dd[1] * mm[2][2] + dd[0] * mm[1][2] * mm[2][0] + mm[1][0] * dd[2] * mm[0][2] 
				   - mm[2][0] * dd[1] * mm[0][2] - dd[2] * mm[1][2] * mm[0][0] - mm[1][0] * dd[0] * mm[2][2];

	float det2 = mm[0][0] * mm[1][1] * mm[2][2] + mm[0][1] * dd[1] * mm[2][0] + mm[1][0] * dd[2] * dd[0] 
				   - mm[2][0] * mm[1][1] * dd[0] - dd[2] * dd[1] * mm[0][0] - mm[1][0] * mm[0][1] * mm[2][2];
	cout << "\n------------------------------------------------------\n";
	cout << "\nResult: " << det2/main_det << "*x^2 + " << det1/main_det << "*x " << det0/main_det << "\n";
	cout << "\n------------------------------------------------------\n";
	return 0;
}