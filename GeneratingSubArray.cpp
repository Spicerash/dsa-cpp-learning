/*
Given an array, generate all the possible subarrays of the given array using recursion.

Approach: We use two pointers start and end to maintain the starting and ending point of the array and follow the steps given below: 
Stop if we have reached the end of the array
Increment the end index if start has become greater than end
Print the subarray from index start to end and increment the starting index

Time Complexity: O(2n)
Auxiliary Space: O(2n)
*/

#include<iostream>
using namespace std;

void printSubArrays(int arr[], int n, int start, int end) {
    // return if reached the end of the array
    if(end == n) return;
    //Increment end and start from 0
    if(start > end)
        printSubArrays(arr, n, 0, end+1);
    //Print subarray and increment start
    else {
        cout << "[";
        for(int i = start; i < end; i++) 
            cout << arr[i] << ", ";
        cout << arr[end] << "]" <<endl;
        printSubArrays(arr, n, start+1, end);
    }
    return;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printSubArrays(arr, n, 0, 0);

    return 0;
}