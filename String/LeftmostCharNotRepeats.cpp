/*
Given a string, find the leftmost character that does not repeat.
*/

#include<iostream>
using namespace std;

// Returns the leftmost non-repeating character's index.
int leftmostNonRepeatingChar(string s) {
    int maxASCII = 256;
    int freq[maxASCII] = {0}; // frequency array to keep count of no of repetition of characters
    int n = s.size();
    char curr;
    for(int i = 0; i < n; i++) { // to fill frequency array with frequency of individual characters
        freq[s[i]]++;
    }
    for(int i = 0; i < n; i++) { // to check which character has frequency 1 that is only encountered once
        if(freq[s[i]] == 1) return i; // returned the index of that char
    }
    return -1; // if not found
}

int main() {

    string s = "string";
    cout << "Leftmost non-repeating character: ";
    int index = leftmostNonRepeatingChar(s);
    if(index == -1) cout << -1;
    else cout << s[index];

    return 0;
}