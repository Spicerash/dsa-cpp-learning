/*
Print matrix in snake pattern
Given an n x n matrix. In the given matrix, you have to print the elements of the matrix in the snake pattern.

Input: mat[][] = { 
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
Output: 1 2 3 6 5 4 7 8 9

Printing Boundary Elements of a Matrix:
Given a matrix of size n x m. Print the boundary elements of the matrix. Boundary elements are those elements that are not surrounded by 
elements in all four directions, i.e. elements in the first row, first column, last row, and last column

Input:
    1 2 3   
    5 6 7 
    1 2 3 

Output: 

    1 2 3
    5   7
    1 2 3

Printing elements in spiral of a matrix
Given a 2D array, print it in spiral form.
Input: { 
    {1,   2,   3,   4,  5,   6},
    {7,   8,   9,  10,  11,  12},
    {13,  14,  15, 16,  17,  18}}

Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/

#include <iostream>
using namespace std;

// Snake Print
void printSnake(int mat[][3], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i%2 == 0) {
                cout << mat[i][j] << " ";
            }
            else{
                cout << mat[i][cols-1-j] << " ";
            }
        }
    }
    cout << endl;
}

// Print Boundary
void printBoundary(int mat[][3], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == 0 || j == 0 || i == rows-1 || j == cols-1) {
                cout << mat[i][j] << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// Print Spiral
void printSpiral(int mat[][3], int rows, int cols) {
    int rs = 0, cs = 0, re = rows-1, ce = cols-1;
    for(int i = 0; i < (min(rows, cols)+1)/2; i++) {
        // Printing top
        for(int j = cs; j <= ce; j++) {
            cout << mat[rs][j] << " ";
        }
        rs++;
        
        // Printing right
        for(int j = rs; j <= re; j++) {
            cout << mat[j][ce] << " ";
        }
        ce--;

        // Printing bottom
        for(int j = ce; j >= cs; j--) {
            cout << mat[re][j] << " ";
        }
        re--;

        // Printing left
        for(int j = re; j >= rs; j--) {
            cout << mat[j][cs] << " ";
        }
        cs++;
    }
}

int main() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Printing Snake: " << endl;
    printSnake(mat, 3, 3);

    cout << "Printing Boundary: " << endl;
    printBoundary(mat, 3, 3);

    cout << "Printing Spiral: " << endl;
    printSpiral(mat, 3, 3);

    return 0;
}