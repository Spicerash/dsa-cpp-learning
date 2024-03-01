/*
A substring is a contiguous part of a string, i.e., a string inside another string.

Time Complexity: O(nlogn)
Auxiliary Space: O(1)
*/

#include<iostream>
#include<string>
using namespace std;

// Prints substring for the using substr function which takes starting index as first parameter and length needed as second
void printSubstring(string s) {
    for(int i = 0; i < s.size(); i++) {
        for(int j = 1; j <= s.size() - i; j++) {
            cout << s.substr(i,j) << " ";
        }
        cout << endl;
    }
}

int main() {
    string s = "geeks";
    printSubstring(s);
    return 0;
}