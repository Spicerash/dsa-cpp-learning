/*
Given a string, find the leftmost character that repeats.

Input: geeksforgeeks
Output: g

Input: abcdabcd
Output: a

Input: abcd
Output: -1
*/

#include<iostream>
using namespace std;

// Returns index of repeating character from left
int leftmostRepeatingChar(string s) {
    int n = s.size();
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(s[i] == s[j]) return i;
    return -1;
}

int main() {
    string s = "string";
    char repeat = leftmostRepeatingChar(s);
    cout << "Leftmost Repeating Character is: " ;
    if(repeat == -1) cout << -1;
    else cout << s[repeat];

    return 0;
}