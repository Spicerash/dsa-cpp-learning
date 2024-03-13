/*
Sum of Repetitive Elements

You are given an integer n, representing the number of elements. Then, you will be given n elements.
You have to return the sum of repetitive elements i.e. the elements that appear more than one time.
*/

#include<iostream>
#include<map>
using namespace std;

int main() {

    // Input
    int n;
    cin >> n;

    int elements[n];
    for(int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    // Frequency register
    map<int, int> count;
    for(int i = 0; i < n; i++) {
        count[elements[i]]++;
    }

    // If frequency is more than one add element to sum
    int sum = 0;
    for(auto pair: count) {
        if(pair.second > 1) {
            sum += pair.first;
        }
    }

    // Printing result
    cout << "Sum of repetitive elements is " << sum << endl;

    return 0;
}