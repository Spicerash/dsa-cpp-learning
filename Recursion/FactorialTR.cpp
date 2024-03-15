// Tail Recursion

#include <iostream>
using namespace std;

int factTR(int n, int a)
{
    if (n <= 1) // if n is 1 or 0 return a i.e. 1
        return a;

    return factTR(n - 1, n * a); // return tail recursively fact(n - 1) and also the current multiplication to optimize the function using the compiler architecture
}

int fact(int n) // wrapper function
{
    return factTR(n, 1);
}

int main()
{
    int n;
    cout << "Number: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << fact(n) << endl;
}