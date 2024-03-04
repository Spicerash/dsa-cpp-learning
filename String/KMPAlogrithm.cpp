/*
Given a text txt[0 . . . N-1] and a pattern pat[0 . . . M-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that N > M. 

Examples:

Input:  txt[] = “THIS IS A TEST TEXT”, pat[] = “TEST”
Output: Pattern found at index 10

Input:  txt[] =  “AABAACAADAABAABA”
          pat[] =  “AABA”
Output: Pattern found at index 0, Pattern found at index 9, Pattern found at index 12

The KMP matching algorithm uses degenerating property (pattern having the same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst-case complexity to O(n+m). 

The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window. We take advantage of this information to avoid matching the characters that we know will anyway match. 
*/

#include<iostream>
#include<string.h>
using namespace std;

void search(char pat[], char txt[]) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    
    // calculating longest prefix suffix values
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < M) {
        if(pat[len] == pat[i]) lps[i++] = ++len; // If they match increment len and give its value to lps[i] and increment i
        else if(len > 0) len = lps[len-1]; // if they do not match and len > 0 then len = lps[len-1] 
        else lps[i++] = 0;
    }

    i = 0;
    int j = 0;
    while(i < N) { // traversing txt
        if(txt[i] == pat[j]) { // if matched increment i and j by 1
            i++;
            j++;
            if(j == M) { // if j is equal to size of pat then we have found the pattern at i-M
                cout << "Pattern found at index " << i - M << endl;
                j = lps[j - 1];
            }
        }
        else if(j > 0) { // if char don't match we make j equal to the last lps
            j = lps[j-1];
        }
        else i++; // if j is 0 then we increment i
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";

    search(pat, txt);

    return 0;
}