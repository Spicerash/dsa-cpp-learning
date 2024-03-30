/*
Given two matrices, the task is to multiply them and print matrix. Matrices can either be square or rectangular
Input: mat1[m][n] = { {1, 1}, {2, 2} }
mat2[n][p] = { {1, 1}, {2, 2} }
Output: 
3 3
6 6
*/
#include <iostream>
using namespace std;
#define R1 2
#define CES 2 // common end of first and start of second
#define C2 2

// Matrix Multiplier and printer
void printMatMul(int mat1[][CES], int mat2[][C2]) {
    for(int i = 0; i < R1; i++) {
        for(int j = 0; j < CES; j++) {
            int temp = 0;
            for(int k = 0; k < CES; k++) {
                temp += mat1[i][k] * mat2[k][j];
            }
            cout << temp << " ";
        }
        cout << endl;
    }
}

int main() {
    
    int mat1[R1][CES] = {{1, 1}, {2, 2}};
    int mat2[CES][C2] = {{1, 1}, {2, 2}};

    printMatMul(mat1, mat2);

    return 0;
}