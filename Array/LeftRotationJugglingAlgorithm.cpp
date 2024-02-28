/* A Juggling Algorithm for Left Rotation of Array
For Details: https://www.geeksforgeeks.org/array-rotation/?ref=lbp
Instead of moving one by one, divide the array into different sets where the number of sets is equal to the GCD of N and d (say X. So the elements which are X distance apart are part of a set) and rotate the elements within sets by 1 position to the left. 

Calculate the GCD between the length and the distance to be moved.
The elements are only shifted within the sets.
We start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

Time complexity : O(N) 
Auxiliary Space : O(1)
*/

#include<iostream>
using namespace std;

// implementation of the Euclidean algorithm to find the greatest common divisor
int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}

void JugglingLeftRotate(int *arr, int n, int d) {
    d = d % n; // To make the value of d in the range of n
    int gcd = GCD(n, d);

    for(int i = 0; i < gcd; i++) {
        int temp = arr[i];
        int j = i;

        while(true) {
            int k = j + d;
            if(k >= n)
                k = k - n;

            if(k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {2, 6, 11, 17, 19, 22, 25};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    JugglingLeftRotate(arr, arrSize, d);

    //Printing array
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}