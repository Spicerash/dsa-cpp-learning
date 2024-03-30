/*
Matrix
A matrix is a two-dimensional array that consists of rows and columns.
*/

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int main() {

    int r = 3;
    int c = 3;

    // Initialization
    int num[r][c] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    /*
    1 2
    3 4
    */

    // Accessing elements
    //cout << num1[0][0];

    // Printing elements in the array
    cout << "Printing Matrix: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    // Search in Matrix
    int key = 5;
    bool is = false;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(key == num[i][j]) {
                is = true;
                goto end;
            }
        }
    }
    end:

    cout << key << ": " << (is == 1 ? "True" : "False") << endl;

    // Printing diagonals of a matrix
    cout << "Principal Diagonal: ";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i == j) {
                cout << num[i][j] << " ";
            }
        }
    }
    cout << endl;

    cout << "Secondary Diagonal: ";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(j == c-i-1) {
                cout << num[i][j] << " ";
            }
        }
    }

    // Sorting matrix using temp array
    int temp[r*c], k = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            temp[k++] = num[i][j];
        }
    }
    sort(temp, temp+k);
    k = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            num[i][j] = temp[k++];
        }
    }
    cout << endl;

    cout << "Sorted Matrix: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    // Rotating a Matrix 180 degrees
    /*
    Procedure according to geeks
    (transpose
    reverse column)X2
    */

   // Transpose
    for(int i = 0; i < r-1; i++) {
        for(int j = i+1; j < c; j++) {
            swap(num[i][j], num[j][i]);
        }
    }

    // Reverse Columns
    for(int i = 0; i < r/2; i++) {
        for(int j = 0; j < c; j++) {
            swap(num[i][j], num[r-1-i][j]);
        }
    }

    // Transpose
    for(int i = 0; i < r-1; i++) {
        for(int j = i+1; j < c; j++) {
            swap(num[i][j], num[j][i]);
        }
    }

    // Reverse Columns
    for(int i = 0; i < r/2; i++) {
        for(int j = 0; j < c; j++) {
            swap(num[i][j], num[r-1-i][j]);
        }
    }

    // Rotated 180deg
    cout << "Printing Matrix: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}