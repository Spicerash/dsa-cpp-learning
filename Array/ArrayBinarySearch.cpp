/* Binary search is a mechanism used to find the given elements from the sorted array by continuously halving the array and then searching specified elements from a half array. And the process goes on till the match is found. It works only the sorted data structures. The time complexity of the binary search algorithm is O (log n). */

#include<iostream>
using namespace std;

// This function will return the index of the element if found else -1
int arrayBinarySearch(int *arr, int arrSize, int key) {
    int beg = 0;
    int end = arrSize - 1; // will point to the last element in the array

    // calculation of mid
    while(beg <= end) {
        int mid = (beg + end) / 2;

        if(arr[mid] == key)  // Element found
            return mid;

        if(arr[mid] < key) // Element is in the right half
            beg = mid + 1;
        
        else if(arr[mid] > key) // Element is in the left half
            end = mid - 1; 
    }
    return -1;
}

int main() {
    int arr[] = {2, 6, 11, 17, 19, 22, 25}; // Sorted Array
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int key = 17;

    int keyIndex = arrayBinarySearch(arr, arrSize, key);
    if(keyIndex == -1) 
        cout << "Element not found.";
    else 
        cout << key << " is at index " << keyIndex;
    return 0;
}