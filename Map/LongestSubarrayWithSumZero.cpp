/*
Given an array arr[] of length n, find the length of the longest subarray with a sum equal to 0
Input: n = 9
arr[] = {15, -1, 2, -8, 1, 7, 10, 23}
Output: 5
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayLengthWithSumZero(int arr[], int n)
{
    unordered_map<int, int> cumulativeFrequency;
    int longestLength = 0, prefixSum = 0, precedingZeroes = 0;
    for (int i = 0; i < n; i++)
    {
        // calculates prefixSum i.e. sum of current element in array with the previous one; for the first element it will take the same value as prefixSum
        prefixSum += arr[i];
        
        if(prefixSum == 0) longestLength = i+1;

        // if the prefixSum is reencountered change the longestLength
        if (cumulativeFrequency.find(prefixSum) != cumulativeFrequency.end())
        {
            longestLength = max(longestLength, i - cumulativeFrequency[prefixSum]);
        }
        // else register index
        else
        {
            cumulativeFrequency[prefixSum] = i;
        }
    }
        if(arr[0] == 0) longestLength++;
    return longestLength;
}

int main()
{
    // Input
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Longest subarray length with sum 0: " << longestSubarrayLengthWithSumZero(arr, n);

    return 0;
}