/* 
Can you make the strings equal?
Given an array of strings. You can move any number of characters from one string to any other string any number of times.
You just have to make all of them equal.
Print "Yes" if you can make every string in the array equal by using any number of operations otherwise print "No".

eg.
Input: ["collegeee", "coll", "collegge"]
Output: Yes
Explanation: string at 1 index can take two 'e' from 0 index string and one 'g' from 2 index string.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

bool canYouMakeTheStringsEqual(string input[], int n) {

    // map for storing the frequency of all characters
    unordered_map<char, int> freqOfChar;
    for(int i = 0; i < n; i++) {
        for(char ch: input[i]) {
            freqOfChar[ch]++;
        }
    }

    for(pair<char, int>pair: freqOfChar) {
        if(pair.second % n != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    // Input
    int n;
    cin >> n;

    string input[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    if(canYouMakeTheStringsEqual(input, n)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }       

    return 0;
}