/*
Given a string of size n, write functions to perform the following operations on a string-
Left (Or anticlockwise) rotate the given string by d elements (where d <= n)
Right (Or clockwise) rotate the given string by d elements (where d <= n)

// Left rotate string s by d (Assuming d <= n)
leftRotate(s, d)
  reverse(s, 0, d-1); // Reverse substring s[0..d-1]
  reverse(s, d, n-1); // Reverse substring s[d..n-1]
  reverse(s, 0, n-1); // Reverse whole string.  
// Right rotate string s by d (Assuming d <= n)
rightRotate(s, d)
  // We can also call above reverse steps
  // with d = n-d.
  leftRotate(s, n-d)  

Time Complexity: O(N), where N is the size of the given string.
Auxiliary Space: O(1), no extra space is required, so it is a constant.
*/

#include<iostream>
#include<algorithm>
using namespace std;

// Function to left rotate by d points in place
void leftRotate(string &s, int d) {
    d = d % s.size();
    // First reverse the string from 0 to d-1
    reverse(s.begin(), s.begin()+d);
    // Reverse from d to n-1
    reverse(s.begin()+d, s.end());
    // Reverse the whole string
    reverse(s.begin(), s.end());
}

void rightRotate(string &s, int d) {
    d = d % s.size();
    leftRotate(s, s.size()-d);
}

int main() {

    string s = "string";
    int d = 10;

    leftRotate(s, d);
    cout << "Result: " << s << endl;

    rightRotate(s,d);
    cout << "Result: " << s << endl;

    return 0;
}