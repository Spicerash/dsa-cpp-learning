/*
Given an array of length n and a target, return a pair whose sum is equal to the target. if there is no pair present, return -1.

Input: n = 7
Elements = [1, 4, 5, 11, 13, 10, 2]
Target = 13

Output: [3,6]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns a pair of indexes that will sum up to the target if pair doesn't exist returns -1, -1
pair<int, int> PairWhoseSum(vector<int> nums, int target)
{
    unordered_map<int, int> index;
    for (int i = 0; i < nums.size(); i++)
    {
        // if the required number to reach the target is already in the map get its index and returns with current index
        if (index.find(target-nums[i]) != index.end())
        {
            return make_pair(index[target - nums[i]], i);
        }
        // else add the index of current number to the map
        else
        {
            index[nums[i]] = i;
        }
    }
    return make_pair(-1, -1);
}

int main()
{

    // Input
    int n;
    cin >> n;
    vector<int> elements(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elements[i];
    }

    int target;
    cin >> target;

    pair<int, int> result = PairWhoseSum(elements, target);

    cout << "[" << result.first << " " << result.second << "]" << endl;

    return 0;
}