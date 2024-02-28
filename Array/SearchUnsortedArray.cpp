/* Search Operation:
In an unsorted array, the search operation can be performed by linear traversal from the first element to the last element. 
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

int main() {
    int arr[] = {13, 12, 17, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 17;
    int index = Search(arr, size, key);
    if(key == -1) 
        cout << "Element not found.";
    else 
        cout << key << " is at index " << index;    
    return 0;
}