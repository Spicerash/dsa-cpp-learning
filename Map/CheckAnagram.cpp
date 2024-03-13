/*
Check Anagram
An anagram of a string is another string that contains the same characters, only the order of characters can be different. 
For example, "abcd" and "dabc" are anagram of each other.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

bool areAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    
    unordered_map<char, int> freq;

    for(int i = 0; i < str1.length(); i++) {
        freq[str1[i]]++;
        freq[str2[i]]--;
    }

    for(auto ele: freq) {
        if(ele.second != 0) return false;
    }
    return true;
}

int main() {

    // Input
    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << (areAnagram(str1,str2) ? "True" : "False") << endl;

    return 0;
}