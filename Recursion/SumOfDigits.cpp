// Sum of Digits of a number
#include<iostream>
using namespace std;

int sumOfDigitsTR(int n, int sum) {
    if(n == 0) return sum; // returns sum calculated when no digits are left
    return sumOfDigitsTR(n/10, sum + (n%10)); // recursive call for the number left after removing unit place digit and adding it to sum and passing both
}

int sumOfDigits(int n) { // wrapper function
    return sumOfDigitsTR(n, 0);
}

int main() {
    // Input
    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Sum of Digit of " << n << ": " << sumOfDigits(n) << endl;

    return 0;
}