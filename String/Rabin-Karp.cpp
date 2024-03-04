/*
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
Given a text T[0. . .n-1] and a pattern P[0. . .m-1], write a function search(char P[], char T[]) that prints all occurrences of P[] present in T[] using Rabin Karp algorithm. You may assume that n > m.

Input:  T[] = “THIS IS A TEST TEXT”, P[] = “TEST”
Output: Pattern found at index 10

Input:  T[] =  “AABAACAADAABAABA”, P[] =  “AABA”
Output: Pattern found at index 0
              Pattern found at index 9
              Pattern found at index 12

The Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text, and if the hash values match then only it starts matching individual characters.
*/

#include<iostream>
#include<string.h>
using namespace std;

void search(char pat[], char txt[], int mod) {
    int b = 256; // base
    int h = 1; // hash
    int N = strlen(txt);
    int M = strlen(pat);
    int p = 0, t = 0, i, j;

    // Due to this loop h = pow(d, M - 1) % q
    for(i = 0; i < M - 1; i++) {
        h = (h * b) % mod;
    }

    // Calculate hash value of pattern and first window of txt
    for(i = 0; i < M; i++) {
        p = (b * p + pat[i]) % mod;
        t = (b * t + txt[i]) % mod;
    }

    // Sliding the window
    for(i = 0; i <= N - M; i++) {
        // if the hash value match for pattern and window then check
        if(p == t) {
            for(j = 0; j < M; j++)
                if(txt[i+j] != pat[j])
                    break;
        
            if(j == M) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text
        if(i < N - M) {
            t = (b * (t - txt[i] * h) + txt[i + M]) % mod;

            // making t positive just in case it is negative
            if(t < 0) t = (t+mod);
        }
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    int mod = 11;

    search(pat, txt, mod);

    return 0;
}