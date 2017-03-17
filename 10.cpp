#include <iostream>
#include <cmath>

using namespace std;



int main()
{

        //lab ¹ 10(13) var. 24

        // y`1 = x*y1 + x^2*y2*y3
        // y`2 = -y1 - y2 + y3^2
        // y`3 = x*e^(-(y1 + y2))
        //    x = [0,3] , y1(0) = -0,3 , y2(0) = 0,5 , y3(0) = 1

    float x = 0;
    float y1 , y2, y3, y10 = -0.3 , y20 = 0.5, y30 = 1;
    float a = 0; // range
    float b = 3; // range
    float h = (b - a)/10;

    cout << "x=" << x << " y1=" << y10 << " y2=" << y20 << " y3=" << y30 << endl;

    for(int i =0; i < 10; i++)
    {
        x += h;
        y1 = y10 + h*(x*y10 + x*x*y20*y30);       
        y2 = y20 + h*(-y10 - y20 -y30*y30);  
        y3 = y30 + h*(x*exp(-(y10 + y20)));  

        // construction: y = y0 + h(f(y1, y2, y3, x)); f at the point x0 + ih, i - number of the step  == numerical integration

        cout << "x=" << x << " y1=" << y1 << " y2=" << y2 << " y3=" << y3 << endl;

        y10 = y1;
        y20 = y2;
        y30 = y3;
    }

    return 0;

}
