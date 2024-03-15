// N to One Number Printing using Recursion
#include <iostream>
using namespace std;

void printNToOne(int n)
{
    // base condition to print number only till one
    if (n < 1)
        return;
    cout << n << " "; // printing n
    printNToOne(n - 1); // recursive call to n-1
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