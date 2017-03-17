#include <iostream>
#include <vector>
#include <math.h>

typedef std::vector<float> vect;

const float y_from_zero = 0.0; 				// y(0)
float f(float x, float y) {					
	return ((0.8 - y*y) * cos(x)) + (0.3*y);	// f(x,y)
}

void calculate(vect&, vect&);

int main() {
	vect* X = new vect();
	vect* Y = new vect();
	calculate(*X, *Y);

	for (int i = 0; i < X->size(); ++i) {
		std::cout << Y->at(i) << std::endl;
	}
}

void calculate(vect& X, vect& Y) {
	float a = 0.0;
	float h = 0.1;
	float y_prvs, x_prvs;

	for (int i = 0; i < 11; ++i) {
		float x = a + h*i;
		float y = i>0? y_prvs + h*f(x_prvs, y_prvs) : y_from_zero;
		y_prvs = y;
		x_prvs = x;
		X.push_back(x);
		Y.push_back(y);
	}
}
