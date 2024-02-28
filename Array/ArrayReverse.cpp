/* Array reverse or reverse a array means changing the position of each number of the given array to its opposite position from end, i.e. if a number is at position 1 then its new position will be Array.length, similarly if a number is at position 2 then its new position will be Array.length – 1, and so on. */

#include<iostream>
using namespace std;

// Function to reverse Array in place
void ArrayReverse(int *arr, int arrSize) {
    for(int i = 0; i < arrSize/2; i++) {
        
        // This is a swap operation without the need of the third variable but it can be replaced by swap(arr[i], arr[arrSize-1-i]);
        arr[i] = arr[arrSize-1-i] + arr[i];
        arr[arrSize-1-i] = arr[i] - arr[arrSize-1-i];
        arr[i] = arr[i] - arr[arrSize-1-i];
    }
}

int main() {
    int arr[] = {2, 6, 11, 17, 19, 22, 25};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ArrayReverse(arr, arrSize);

    // Printing the Reversed array
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}