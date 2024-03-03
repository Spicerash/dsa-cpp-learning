/*
Given a string, find the lexicographic rank of it in O(n) time.
*/

#include<iostream>
using namespace std;
#define MAX_CHAR 256

int fact(int n) {
    if(n == 0 || n == 1) return 1;
    return n * fact(n-1);
}

// Basic function to understand lexicographical rank with time complexity O(n^2)
int lexicographicalRank(string s) {
    int n = s.size();
    int rank = 1;
    for(int i = 0; i < n-1; i++) {
        int count = 0;
        for(int j = i+1; j < n; j++)
            if(s[i] > s[j]) count++;
        rank += count * fact(n-i-1);
    }
    return rank;
}

// for O(n)
int lexicographicalORank(string s) {
    int max = 256;
    int n = s.size();
    int mul = fact(n);
    int rank = 1, i;

    int count[max] = {0}; // Initializing count array to 0

    for(i = 0; i < n; i++) // registering the count of every character is string
        count[s[i]]++;
    for(i = 1; i < max; i++) // building cumulative sum array
        count[i] += count[i-1];

    for(i=0; i < n; i++) {
        mul /= n-i; // used to calculate contribution of each character in the rank
        rank += count[s[i]-1] * mul; // rank is calculated for current character contribution
        for(int j = s[i]; j < max; j++) { // it decrements the count of characters greater than or equal to s[i]
            count[j]--;
        }
    }
    return rank;
}

int main() {

    string s = "dacb";
    cout << "Lexicographical rank of " << s << " is " << lexicographicalORank(s) << endl;

    return 0;
}