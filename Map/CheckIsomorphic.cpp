/*
Check whether two strings are isomorphic of each other. Return true if they are else return false.
Two strings are isomorphic of each other if there is a one-to-one mapping possible for every character of the first string to every
character of second string and all occurrences of every character of the first string to every character in first string maps to the same
character in second string.
*/

#include <iostream>
#include<unordered_map>
using namespace std;

bool areIsomorphic(string s1, string s2) {
    // if length is not equal return
    if(s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, char> link;

    // checks if characters from s1 map with characters in s2
    for(int i = 0; i < s1.length(); i++) {
        // checks if the character is already mapped
        if(link.find(s1[i]) != link.end()) {
            // checks if the value at s1's ith charater in link is equal to s2's ith character
            if(link[s1[i]] != s2[i]) {
                return false;
            }
        }
        // if not mapped maps it
        else {
            link[s1[i]] = s2[i];
        }
    }

    link.clear();

    // ensures one to one relationship from both sides
    for(int i = 0; i < s1.length(); i++) {
        if(link.find(s2[i]) != link.end()) {
            if(link[s2[i]] != s1[i]) {
                return false;
            }
        }
        else {
            link[s2[i]] = s1[i];
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << (areIsomorphic(s1,s2) ? "Are Isomorphic" : "Not Isomorphic") << endl;

    return 0;
}