// Factorial

#include <iostream>
using namespace std;

int fact(int n, int count)
{
    if (n == 0 || n == 1) // base case
    {
        count ++;
        return 1;
    }
    count++;
    cout <<"count is: " << n << count;
    return n * fact(n - 1, count); // recursive call
}

int main()
{
    int n;
    cout << "Number: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << fact(n,0) << endl;
}