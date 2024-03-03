/*
Given a string of lowercase characters from ‘a’ – ‘z’. We need to write a program to print the characters of this string in sorted order.
*/

#include<iostream>
using namespace std;

// Function to print frequency of each character in a string.
void printFrequency(string s) {
    int alpha = 26;
    int freq[alpha] = {0}; // Initializes array to 0 for frequency count
    for(int i = 0; i < s.size(); i++) { // Fills the array with frequency of char in string
        freq[s[i] - 'a']++;
    }
    for(int i = 0; i < alpha; i++) { // prints the char followed by count in alphabetical order
        if(freq[i] != 0) cout << (char)(i+'a') << freq[i];
    }
}

int main() {
    string s = "string";
    printFrequency(s);
    return 0;
}