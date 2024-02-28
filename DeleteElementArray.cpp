/* Deleting Element from a Array: 
In the delete operation, the element to be deleted is searched using the linear search, and then the delete operation is performed followed by shifting the elements. 
Time Complexity: O(N) 
Auxiliary Space: O(1)
*/

#include<iostream>
using namespace std;

// Returns index of key else if not found returns -1
int Search(int *arr, int n, int k) {
    // Linear Search
    for(int i = 0; i < n; i++) {
        if(arr[i] == k) return i;
    }
    return -1;
}

// Returns new array size after deleting element if the element is not found then it returns the same size
int Delete(int *arr, int n, int element) {
    int index = Search(arr, n, element);

    for(int i = index; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = 0;
    return n-1;
}

int main() {
    int arr[20] = {13, 12, 17, 2, 10};
    int element = 17;
    int n = 5;

    // Array Before Insert
    cout << "Array Before Delete: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    n = Delete(arr, n, element);

    // Printing Array
    cout << "Array After Delete: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}