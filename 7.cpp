#include <iostream>
#include "math.h"
#include <vector>

using namespace std;
//
void solve (float a[4][4], float x[4], float *y);
void proizv (float a[4][4], float x[4],float *y);
//


int main()
{
	setlocale(LC_ALL, "Russian");
float a [4][4];	
{ //по варианту
	a[0][0] = 1.6;
	a[0][1] = 1.6;
	a[0][2] = 1.7;
	a[0][3] = 1.8;
		a[1][0] = 1.6;
		a[1][1] = 2.6;
		a[1][2] = 1.3;
		a[1][3] = 1.3;
	a[2][0] = 1.7;
	a[2][1] = 1.3;
	a[2][2] = 3.6;
	a[2][3] = 1.4;
		a[3][0] = 1.8;
		a[3][1] = 1.3;
		a[3][2] = 1.4;
		a[3][3] = 4.6;
}
float l;
float x0 [4] = {1,1,1,1}; //прост зачем то
float x [4] = {1,1,1,1};
float y [4] = {1,1,1,1};
float *yy ;
double n ;
//
	float n1 = sqrt(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]+x[3]*x[3]);
	int k = 0;
	while(n1>0.001)
	{
			for (int i = 0; i<4; i++)
			{
				for (int j = 0; j<4; j++)
				{
					y[i] = a[i][j]*x[j];
				}
			}
	l = x[0]*y[0] + x[1]*y[1] + x[2]*y[2] + x[3]*y[3];//ну допустим	l = x*y ????/////////////////
	n = sqrt(y[0]*y[0]+y[1]*y[1]+y[2]*y[2]+y[3]*y[3]);
	for (int i = 0; i<4; i++)	y[i] = y[i] / n;
	n1 = sqrt( (y[0]-x[0])*(y[0]-x[0]) + (y[1]-x[1])*(y[1]-x[1]) + (y[2]-x[2])*(y[2]-x[2]) + (y[3]-x[3])*(y[3]-x[3]) );
	for (int i = 0; i<4; i++) x[i] = y[i];
	k++;
	if (k>100) break;
	} 


	cout<<"максимальное собственное число = "<<l<<endl;
//+
float a1 [4][4];	
	for (int i = 0; i<4; i++)
			{
				for (int j = 0; j<4; j++)
				{
					a1[i][j] = a[i][j];
				}
			}
	for (int i = 0; i<4; i++) a1[i][i] = a1[i][i] - l;
//+
	while(n>0.001)
	{
			yy = y;
			solve(a1 , x0, yy );
			n = sqrt(y[0]*y[0]+y[1]*y[1]+y[2]*y[2]+y[3]*y[3]);
			for (int i = 0; i<4; i++)
			{
				y[i] = y[i] / n;
				x0[i] = fabs(y[i]) - fabs(x0[i]);
			}
			n = sqrt(sqrt(x0[0]*x0[0]+x0[1]*x0[1]+x0[2]*x0[2]+x0[3]*x0[3]));
			for (int i = 0; i<4; i++) x0[i] = y[i];
	}
	cout<<"собственный вектор для него = ("<<x0[0]<<", "<<x0[1]<<", "<<x0[2]<<", "<<x0[3]<<") "<<endl;
//		yy=y;
//		proizv(a,x0,yy);
//			cout<<y[0]<<", "<<y[1]<<", "<<y[2]<<", "<<y[3]<<endl;
//		
//			for (int i = 0; i<4; i++) y[i] = l*x0[i];
//			cout<<y[0]<<", "<<y[1]<<", "<<y[2]<<", "<<y[3]<<endl;
//	проверка , показывающая неверный результат)
	
return 0;	
}

void proizv (float a[4][4], float x[4], float* yy)///////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
				for (int i = 0; i<4; i++)
			{
				*(yy+i) = 0;
				for (int j = 0; j<4; j++)
				{
					*(yy+i) += a[i][j]*x[j];
				}
			}
			
}
///// 
void solve (float a[4][4], float x[4],float *yy) {
	float a1[4][4];//обратная
	float aa[4][8];
	float b;
			for (int i = 0; i<4; i++)
			{
				for (int j = 0; j<4; j++)
				{
					aa[i][j] = a[3-i][j]; //меняб местами чтоб нолей на диагонали не оаказалось, в обратной диагонали нолей нигде нет, можно не париться при преобюразовании
				}
				for (int k = 4; k<8; k++)
				{
					aa[i][k] = 0.0;
					if ( k-4 == 3-i) aa[i][k] = 1.0;
				}
			}
			
//				for (int i = 0; i<4; i++)
//			{
//				for (int j = 0; j<8; j++)
//				{cout<<aa[i][j]<<", ";	}
//				cout<<endl;
//			}
	b = aa[0][0];
	for (int i = 0; i<8; i++) aa[0][i] = aa[0][i]/b;
		if (aa[0][0] < 0) aa[0][0] = -1*aa[0][0];	// в левом верхнем 1
			for (int i = 1; i<4; i++)  
			{
				for (int j = 0; j<8; j++) aa[i][j] = aa[i][j]- aa[0][j]*aa[i][0]; //в остальном левом столбике 0
			}
	b = aa[1][1];
	for (int i = 0; i<8; i++)	aa[1][i] = aa[1][i] / b;

		if (aa[1][1] < 0) aa[1][1] = -1*aa[1][1];	// в (1.1) единица
			for (int i = 0; i<4; i++)  
			{
				if(i !=1 ) for (int j = 0; j<8; j++) aa[i][j] = aa[i][j]- aa[1][j]*aa[i][1]; //в остальном 1 столбике 0
			}
	b = aa[2][2];					
	for (int i = 0; i<8; i++)	aa[2][i] = aa[2][i] / b;
		if (aa[2][2] < 0) aa[2][2] = -1*aa[2][2];// в (2.2) единица
			for (int i = 0; i<4; i++)  
			{
				if(i !=2 ) for (int j = 0; j<8; j++) aa[i][j] = aa[i][j]- aa[2][j]*aa[i][2]; //в остальном 2 столбике 0
			}
	b = aa[3][3];					
	for (int i = 0; i<8; i++)	aa[3][i] = aa[3][i] / b;
		if (aa[3][3] < 0) aa[3][3] = -1*aa[3][3];// в (3.3) единица
			for (int i = 0; i<4; i++)  
			{
				if(i !=3 ) for (int j = 0; j<8; j++) aa[i][j] = aa[i][j]- aa[3][j]*aa[i][3]; //в остальном 3 столбике 0
			}
	//вроде слева единичная, справа то что надо? да+

	for (int i = 0; i<4; i++)
			{
				for (int j = 0; j<4; j++)
				{
					a1[i][j] = aa[i][4+j]; 
					//cout<<a1[i][j]<<", ";
				}	
			//	cout<<endl;	
			}
	//в а1 обратная	+	
	
	proizv (a1, x, yy);//a*y=x; y= a1*x;
				//	cout<<"! "<<*yy<<", "<<*(yy+1)<<", "<<*(yy+2)<<", "<<*(yy+3)<<endl;
				
}


