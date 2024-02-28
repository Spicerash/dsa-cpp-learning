/*
Given an Array of size N and a value K, around which we need to right rotate the array.
Input: Array[] = {1, 3, 5, 7, 9}, K = 2.
Output: 7 9 1 3 5
Explanation:
After 1st rotation – {9, 1, 3, 5, 7}After 2nd rotation – {7, 9, 1, 3, 5}
*/

#include<iostream>
using namespace std;

void PrintRightRotation(int *arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        if(i < k)
            cout << arr[n - k + i] << " "; // Prints rightmost element k element in the desired order
        else
            cout << arr[i - k] << " "; // Print array after k element
    }
}

int main() {
    int arr[] = {2, 6, 11, 17, 19, 22, 25};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    PrintRightRotation(arr, arrSize, k);
    return 0;
}