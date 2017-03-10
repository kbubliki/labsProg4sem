#include <iostream>


using namespace std;

// function f(x) by points (1st part of the assignment) var ¹ 24

float x1 = 0.05;

float x2 = 0.19;

float x3 = 0.21;

float x4 = 0.27;

float x5 = 0.32;

float x6 = 0.34;

float x7 = 0.39;

float x8 = 0.45;


float y1 = 4.4817;

float y2 = 4.9530;

float y3 = 5.4739;

float y4 = 6.0496;

float y5 = 6.6859;

float y6 = 7.3891;

float y7 = 8.1662;

float y8 = 9.0250;


float x = 0.412;


//function by points (2nd part of the assignment) var ¹ 24


float *xa = new float [10];



float *ya = new float [10];




float xx = 1.354;





//Math operations part 1

float f2(float a, float b, float fa, float fb)
{
    return (fb - fa)/(b - a);
};

float f3(float a, float b, float c, float fa, float fb, float fc)
{
    return (f2(b, c, fb, fc) - f2(a, b, fa, fb))/(c - a);
};

float f4(float a, float b, float c, float d, float fa, float fb, float fc, float fd)
{
    return (f3(b, c, d, fb, fc, fd) - f3(a, b, c, fa, fb, fc))/(d - a);
}

float f5(float a, float b, float c, float d, float e, float fa, float fb, float fc, float fd, float fe)
{
    return (f4(b, c, d, e, fb, fc, fd, fe) - f4(a, b, c, d, fa, fb, fc, fd))/(e - a);
}

float f6(float a, float b, float c, float d, float e, float f, float fa, float fb, float fc, float fd, float fe, float ff)
{
    return (f5(b, c, d, e, f, fb, fc, fd, fe, ff) - f5(a, b, c, d, e, fa, fb, fc, fd, fe))/(f - a);
}

float f7(float a, float b, float c, float d, float e, float f, float g, float fa, float fb, float fc, float fd, float fe, float ff, float fg)
{
    return (f6(b, c, d, e, f, g, fb, fc, fd, fe, ff, fg) - f6(a, b, c, d, e, f, fa, fb, fc, fd, fe, ff))/(g - a);
}

float f8(float a, float b, float c, float d, float e, float f, float g, float h, float fa, float fb, float fc, float fd, float fe, float ff, float fg, float fh)
{
    return(f7(b, c, d, e, f, g, h, fb, fc, fd, fe, ff, fg, fh) - f7(a, b, c, d, e, f, g, fa, fb, fc, fd, fe, ff, fg))/(h - a);
}




float w8(float x, float x1, float x2, float x3, float x4, float x5, float x6, float x7)
{
    return (x - x1)*(x - x2)*(x - x3)*(x - x4)*(x - x5)*(x - x6)*(x - x7);
}

float w7(float x, float x1, float x2, float x3, float x4, float x5, float x6)
{
    return (x - x1)*(x - x2)*(x - x3)*(x - x4)*(x - x5)*(x - x6);
}

float w6(float x, float x1, float x2, float x3, float x4, float x5)
{
    return (x - x1)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
}


float w5(float x, float x1, float x2, float x3, float x4)
{
    return (x - x1)*(x - x2)*(x - x3)*(x - x4);
}

float w4(float x, float x1, float x2, float x3)
{
    return (x - x1)*(x - x2)*(x - x3);
}

float w3(float x, float x1, float x2)
{
    return (x - x1)*(x - x2);
}

float w2(float x, float x1)
{
    return (x - x1);
}



void interpolation(float x1, float x2, float x3, float x4, float x5, float x6, float x7, float x8, float y1, float y2, float y3, float y4, float y5, float y6, float y7, float y8)
{
    cout << "f(x) = " << f8(x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3, y4, y5, y6, y7, y8) << "*(x - " << x1 <<")*(x - " << x2 << ")*(x - " << x3 << ")*(x - " << x4 << ")*(x - " << x5 << ")*(x - " << x6 << ")*(x - " << x7 << ") + ";
    cout << f7(x1, x2, x3, x4, x5, x6, x7, y1, y2, y3, y4, y5, y6, y7) << "*(x - " << x1 << ")*(x - " << x2 << ")*(x - " << x3 << ")*(x - " << x4 << ")*(x - " << x5 << ")*(x - " << x6 << ") + ";
    cout << f6(x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6) << "*(x - " << x1 << ")*(x - " << x2 << ")*(x - " << x3 << ")*(x - " << x4 << ")*(x - " << x5 << ") + ";
    cout << f5(x1, x2, x3, x4, x5, y1, y2, y3, y4, y5) << "*(x - " << x1 << ")*(x - " << x2 << ")*(x - " << x3 << ")*(x - " << x4 << ") + ";
    cout << f4(x1, x2, x3, x4, y1, y2, y3, y4) << "*(x - " << x1 << ")*(x - " << x2 << ")*(x - " << x3 << ") + ";
    cout << f3(x1, x2, x3, y1, y2, y3) << "*(x - " << x1 << ")*(x - " << x2 << ") + ";
    cout << f2(x1, x2, y1, y2) << "*(x - " << x1 << ") + ";
    cout << y1<< endl <<endl;
}

void calc(float x, float x1, float x2, float x3, float x4, float x5, float x6, float x7, float x8, float y1, float y2, float y3, float y4, float y5, float y6, float y7, float y8)
{
    cout << "f(" << x << ") = " << f8(x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3, y4, y5, y6, y7, y8)*w8(x, x1, x2, x3, x4, x5, x6, x7) +
                        f7(x1, x2, x3, x4, x5, x6, x7, y1, y2, y3, y4, y5, y6, y7)*w7(x, x1, x2, x3, x4, x5, x6) +
                        f6(x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6)*w6(x, x1, x2, x3, x4, x5) +
                        f5(x1, x2, x3, x4, x5, y1, y2, y3, y4, y5)*w5(x, x1, x2, x3, x4) +
                        f4(x1, x2, x3, x4, y1, y2, y3, y4)*w4(x, x1, x2, x3) +
                        f3(x1, x2, x3, y1, y2, y3)*w3(x, x1, x2) +
                        f2(x1, x2, y1, y2)*w2(x, x1) + y1;
    cout << endl << endl;
}

//Math operations part 2

int findx(float *xa, float h)
{
  float temp;
  int i;
  for( i = 0; i < 10; i++)
{
    temp = xx - xa[i];
    if((temp > 0)&&(temp < h))
        break;
}
  return i;
}





int main()
{
    cout << "Part 1" <<endl;

    interpolation(x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3, y4 ,y5 ,y6 ,y7 ,y8);

    calc(x, x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3, y4 ,y5 ,y6 ,y7 ,y8);

    cout << "Part 2 (interpolation forward)" <<endl;

    xa[0] = 4.35;

    xa[1] = 4.60;

    xa[2] = 4.85;

    xa[3] = 5.10;

    xa[4] = 5.35;

    xa[5] = 5.60;

    xa[6] = 5.85;

    xa[7] = 6.10;

    xa[8] = 6.35;

    xa[9] = 6.60;



    ya[0] = 16.3597;

    ya[1] = 17.7334;

    ya[2] = 18.7686;

    ya[3] = 20.0334;

    ya[4] = 22.2846;

    ya[5] = 23.5973;

    ya[6] = 25.0811;

    ya[7] = 26.5278;

    ya[8] = 28.3944;

    ya[9] = 29.9902;

    float h = xa[1] - xa[0];

    int k = findx(xa, h);

    float q = ((xx - xa[k])/h);

    float *deltay = new float [10];

    for (int i = 0; i < 9; i++)
    {
        deltay[i] = ya[i+1] - ya[i];
    }

    float *delta2y = new float [10];

    for (int i = 0; i < 9; i++)
    {
        delta2y[i] = deltay[i+1] - deltay[i];
    }

    float *delta3y = new float [10];

    for (int i = 0; i < 9; i++)
    {
        delta3y[i] = delta2y[i+1] - delta2y[i];
    }

    float *delta4y = new float [10];

    for (int i = 0; i < 9; i++)
    {
        delta4y[i] = delta3y[i+1] - delta3y[i];
    }

    float result = ya[k] + (deltay[k]*q) + (delta2y[k]*q*(q-1))/2 + (delta3y[k]*q*(q-1)*(q-2))/6 + (delta4y[k]*q*(q-1)*(q-2)*(q-3))/24;

    cout << "f(" << xx << ") = " << result << " With accuracy in 10^(-4)." << endl;

    delete [] xa;
    delete [] ya;
    delete [] deltay;
    delete [] delta2y;
    delete [] delta3y;
    delete [] delta4y;

    return 0;
}
