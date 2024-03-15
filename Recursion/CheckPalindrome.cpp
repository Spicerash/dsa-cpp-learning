// Check Palindrome i.e if the reverse string is also the same using recursion

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    if (s == "")
        return true;

    if (s[0] != s[s.length() - 1]) {
        return false;
    }
    return isPalindrome(s.substr(1, s.length()-2));
}

int main()
{
    // Input
    string s;
    cout << "Enter String: ";
    cin >> s;

    if (isPalindrome(s))
        cout << "Is Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}