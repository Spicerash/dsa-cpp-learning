/*
Merge Sort
Merge sort is a recursive algorithm that continuously splits the array in half until it cannot be further divided i.e., the array has 
only one element left (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int left, int mid, int right) { // responsible for merging partitioned array
    int temp[right - left + 1];
    int curr = 0;
    int tempLeft = left;
    int tempMid = mid+1;

    while(tempLeft <= mid && tempMid <= right) { // checks if elements are there in both the partitions and arranges them sorted in temp array
        if(arr[tempLeft] < arr[tempMid]) { // if left partitions currentCheck element is less than right partition then put it in temp array
            temp[curr++] = arr[tempLeft++];
        }
        else { // else right partitions element will be pushed to the temp
            temp[curr++] = arr[tempMid++];
        }
    }

    while(tempLeft <= mid) { // left elements in left partition are pushed in the temp array
        temp[curr++] = arr[tempLeft++];
    }

    while(tempMid <= right) { // right elements in right partition are pushed in the temp array
        temp[curr++] = arr[tempMid++];
    }

    for(int i = left; i <= right; i++) { // copied back to the orginal array
        arr[i] = temp[i-left];
    }
}

void mergeSort(int arr[], int left, int right) { 
    if(left >= right) return; // base case 
    int mid = (left + right)/2; // calculate mid
    mergeSort(arr, left, mid); // sort left half
    mergeSort(arr, mid+1, right); // sort right half
    merge(arr, left, mid, right); // merge both sorted halves
}

int main() {

    int n;
    cout << "Number of elements: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}