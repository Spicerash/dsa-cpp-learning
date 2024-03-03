/*
Given a string of lowercase characters from ‘a’ – ‘z’. We need to write a program to print the characters of this string in sorted order.
An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.

Sort both strings.
Compare the sorted strings: 
If they are equal return True.
Else return False.

Time Complexity: O(N * logN), For sorting.
Auxiliary Space: O(1) as it is using constant extra space
*/

#include<iostream>
using namespace std;

string sortString(string s) {
    int n = s.size();
    // Bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(s[j] > s[j+1]) swap(s[j],s[j+1]);
        }
    }
    return s;
}

bool checkAnagram(string s, string t) {
    if(sortString(s) == sortString(t)) return true;
    return false;
}

int main() {
    string s = "string";
    string t = "trings";
    cout << "Anagram: " << checkAnagram(s, t) << endl;

    return 0;
}