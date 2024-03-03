/*Given a string of lowercase characters from ‘a’ – ‘z’. We need to write a program to print the characters of this string in sorted order.*/

#include<iostream>
using namespace std;

// The function sorts the characters in the string in place
void sortString(string &s) {
    int n = s.size();
    // Bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(s[j] > s[j+1]) swap(s[j],s[j+1]);
        }
    }
}

int main() {
    string s = "string";
    sortString(s);
    cout << "Result: " << s << endl;
}