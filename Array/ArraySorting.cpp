/* Array Sorting
Sorting an array means arranging the elements of the array in a certain order. Generally sorting in an array is done to arrange the elements in increasing or decreasing order.

Bubble Sort: Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large arrays as its average and worst-case time complexity is quite high.

Selection Sort: Selection sort is another sorting technique in which we find the minimum element in every iteration and place it in the array beginning from the first index. Thus, a selection sort also gets divided into a sorted and unsorted subarray.

Insertion Sort: Insertion sort similarly to the way we sort playing cards in our hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed in the correct position in the sorted part.

Merge Sort: It is a sorting algorithm that is based on the Divide and Conquer paradigm. In this algorithm, the array is repeatedly divided into two equal halves and then they are combined in a sorted manner.

Quick Sort: This is a sorting algorithm based on the divide and conquer approach where an array is divided into subarrays by selecting a pivot element (element selected from the array).

Heap Sort: Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.

Counting Sort: Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of elements having distinct key values (kind of hashing). Then do some arithmetic to calculate the position of each element in the output sequence.

Heap and Counting Sort are not covered in the code

https://www.geeksforgeeks.org/array-data-structure/array-sorting/?ref=lbp
*/

#include<iostream>
#include<vector>
using namespace std;

// Function that will bubble sort the array
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i ++){
        int ifSwap = 0;
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ifSwap = 1;
            }
        if(ifSwap == 0) return;
    }
}

// Function that will insertion sort the array
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i ++) {
        for(int j = i; j > 0; j --) {
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
}

// Function that will selection sort the arrays
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int select = arr[i];
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[select]) 
                select = j;
        }
        swap(arr[i], arr[select]);
    }
}

// Function that will merge the arrays
void merge(int arr[], int l, int m, int r) {
    vector<int> vect;
    int curr1 = l;
    int curr2 = m+1;
    while(curr1 <= m && curr2 <= r) {
        if(arr[curr1] < arr[curr2]) vect.push_back(arr[curr1++]);
        else vect.push_back(arr[curr2++]);
    }
    while(curr1 <= m) {
        vect.push_back(arr[curr1++]);
    }
    while(curr2 <= r) {
        vect.push_back(arr[curr2++]);
    }
    for(int i = l; i <= r; i++) {
        arr[i] = vect[i-l];
    }
}

// Function that will merge sort the array
void mergeSort(int arr[], int l, int r) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

// Function for partition for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

//Function for quick sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {13, 12, 17, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Array Before Sorting
    cout << "Array Before Sorting: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n-1);

    // Array after sorting
    cout << "Array After Sorting: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}