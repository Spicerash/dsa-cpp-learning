/*In an unsorted array, the insert operation is faster as compared to a sorted array because we don’t have to care about the position at which the element is to be placed.
To insert at end there should be room in the array
Time Complexity: O(1) 
Auxiliary Space: O(1)
*/

#include<iostream>
using namespace std;

// Inserts element at end of the array
int InsertAtEnd(int *arr, int n, int element, int capacity) {
   if(n>=capacity) return n;
   arr[n] = element;
   return n+1;
}

int main() {
    int arr[20] = {13, 12, 17, 2, 10};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int element = 17;
    int n = 5;

    // Array Before Insert
    cout << "Array Before Insert: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    n = InsertAtEnd(arr, n, element, capacity);

    // Printing Array
    cout << "Array After Insert: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}