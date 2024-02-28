/*Insert at any position
Insert operation in an array at any position can be performed by shifting elements to the right, which are on the right side of the required position

Time complexity: O(N)
Auxiliary Space: O(1)
*/

#include<iostream>
using namespace std;

// Inserts element at a specific index returns new size of array else if capacity <= n returns n

int InsertAtIndex(int *arr, int n, int element, int index, int capacity) {
    if(n >= capacity) return n;
    for(int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    return n+1;
}

int main() {
    int arr[20] = {13, 12, 17, 2, 10};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int element = 17;
    int n = 5;
    int index = 2;

    // Array Before Insert
    cout << "Array Before Insert: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    n = InsertAtIndex(arr, n, element, index, capacity);

    // Printing Array
    cout << "Array After Insert: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}