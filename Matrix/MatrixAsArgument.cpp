/*
Passing matrix as an argument
*/
#include <iostream>
using namespace std;

// Specifying the number of columns
void printMatrixCols(int mat[][3]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Pointer Array
void printMatrixSinglePointer(int *mat[2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Pointer to a pointer
void printMatrixPointerToPointer(int **mat) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    // Specifying the number of columns
    cout << "Specifying number of cols: " << endl;
    int mat[2][3] = {{1, 2, 3},{4, 5, 6}};
    printMatrixCols(mat);

    // Pointer Array
    cout << "Pointer Array: " << endl;
    int *mat2[2]; 
    mat2[0] = new int[3];
    mat2[1] = new int[3];
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[0][2] = 3;
    int temp[3] = {4, 5, 6};
    mat2[1] = temp;
    printMatrixSinglePointer(mat2);
    
    // Pointer to a Pointer
    cout << "Pointer to a pointer: " << endl;
    int **ptp;
    ptp = mat2; // matrix from above
    printMatrixPointerToPointer(mat2);
    
    return 0;
}