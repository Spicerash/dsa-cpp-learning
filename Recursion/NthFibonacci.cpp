// Finding Nth fibonacci number

#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

// use of unordered_map to store fibonacci of nth number when found to reduce the recursive need to recalculate
unordered_map<int, int> lookup_table;

// use of memoization to reduce the time cost of expensive calls
int fib_mem(int n)
{
    // if fibo(n) found in lookup_table
    if (lookup_table.find(n) != lookup_table.end())
    {
        return lookup_table[n];
    }
    // base case
    if (n == 0 || n == 1)
    {
        lookup_table[n] = n;
    }
    // recursive call
    else
    {
        lookup_table[n] = fib_mem(n - 1) + fib_mem(n - 2);
    }
    // return value from the lookup_table of fibo(n)
    return lookup_table[n];
}

int main()
{
    // Start measuring time
    auto begin = chrono::high_resolution_clock::now();

    int n;
    cout << "Number: ";
    cin >> n;

    cout << "Fibonacci at " << n << " is " << fib_mem(n) << endl;

    // Stop measuring time and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

    return 0;
}