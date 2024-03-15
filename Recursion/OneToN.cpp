// One to N Number Printing using Recursion
#include <iostream>
using namespace std;

void printNToOne(int n)
{
    if (n < 1) // base case to only print till 1
        return;
    printNToOne(n - 1); // recursive call with contribution to stop recursion
    cout << n << " "; // printing of number
}

int main()
{
    // Input
    cout << "Number: ";
    int n;
    cin >> n;

    printNToOne(n);

    return 0;
}