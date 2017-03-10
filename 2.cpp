#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {//Вариант 24
    //первое задание работает только для i = 4
    double task[4][2] = { {-2, 27}, {-1, -4}, {0, -1}, {1, -6} };//вставить свои значения
    double **matrix = new double *[4];
    for (int i = 0; i < 4; i++)
    {
        matrix[i] = new double[4];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                matrix[i][j] = task[i][0];
            } else {
                matrix[i][j] = task[i][0] - task[j][0];
            }
        }
    }

    double a[4] = {0 , 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        a[i] = task[i][1];
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                a[i] = a[i] / matrix[i][j] ;
            }
        }
    }
    
    double l[4] = {0, 0, 0, 0};
    double sum_task_x[4] = {0 , 0, 0, 0};
    double comp_task_x[4] = {1 , 1, 1, 1};
    double **hernya = new double *[4];
    for (int i = 0; i < 4; i++)
    {
        hernya[i] = new double[4];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            hernya[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            if (i != j) {
                sum_task_x[i] = sum_task_x[i] + task[j][0];
                comp_task_x[i] = comp_task_x[i] * task[j][0];
                if ((j + 1) % 4 != i) {
                    hernya[i][j] = task[j][0] * task[(j + 1) % 4][0];
                } else {
                    hernya[i][j] = task[j][0] * task[(j + 2) % 4][0];
                }
            }
        }
        l[0] = l[0] + a[i];
        l[1] = l[1] - a[i] * sum_task_x[i];
        for (int q = 0; q < 4; q++) {
            if (q != i) {
                hernya[i][i] = hernya[i][i] + hernya[i][q];
            }
        }
        l[2] = l[2] + a[i] * hernya[i][i];
        l[3] = l[3] - a[i] * comp_task_x[i];
    }
    
    
    for (int i = 0; i < 4; i++) {
        cout << " ("<< l[i] <<"x^"<< (3 - i) << ") +";
    }
    cout << endl;
    
    //////////////////////////////////////////////////////////
    
    double xT = 3.512;//вставить свои значения
    double **matrix_1 = new double *[10];
    for (int i = 0; i < 10; i++)
    {
        matrix_1[i] = new double[8];
    }
    matrix_1[0][0] = 0.20;  matrix_1[2][0] = 10.2316; //вставить свои значения
    matrix_1[0][1] = 0.80;  matrix_1[2][1] = 10.9590; //вставить свои значения
    matrix_1[0][2] = 1.20;  matrix_1[2][2] = 11.4725; //вставить свои значения
    matrix_1[0][3] = 1.70;  matrix_1[2][3] = 12.1483; //вставить свои значения
    matrix_1[0][4] = 2.35;  matrix_1[2][4] = 13.0120; //вставить свои значения
    matrix_1[0][5] = 3.00;  matrix_1[2][5] = 14.0976; //вставить свои значения
    matrix_1[0][6] = 3.14;  matrix_1[2][6] = 16.2134; //вставить свои значения
    matrix_1[0][7] = 3.61;  matrix_1[2][7] = 19.0218; //вставить свои значения
    for (int i = 0; i < 8; i++) {
        matrix_1[1][i] = matrix_1[0][i] - xT;
    }
    for (int i = 3; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            matrix_1[i][j] = 0;
        }
    }
    for (int i = 1; i < 9; i++) {
        for (int j = i ; j < 8; j++) {
            matrix_1[i + 2][j] = 1 /(matrix_1[0][j - i] - matrix_1[0][j]) * (matrix_1[1][j - i]*matrix_1[(i+2) -1][j] -
                                                                           matrix_1[1][j]*matrix_1[(i+2) -1][j -1]);
        }
    }
    cout << matrix_1[9][7] << endl;
//    for (int i = 0; i < 8; i++) {
//        
//        for (int j = 3; j < 10; j++) {
//            cout << matrix_1[j][i] << "\t";
//        }
//        cout << "\n";
//    }
    return 0;
}
