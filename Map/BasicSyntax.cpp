#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    map<int, string> ascMap; // for ascending order of keys in map
    map<int, string, greater<int>> descMap; // for descending order of keys in map

    // Initialization
    map<string, int> directory = {{"Aditya", 10}, {"Hamza", 20}};
    
    // Insertion
    // Time Complexity: O(log n)
    directory.insert(make_pair("Raj", 15));
    directory["Mohan"] = 22;

    // For printing the elements

    // for each loop
    // cout << "Name\t\t" << "Roll No" << endl;
    // for(auto element: directory) {
    //     cout << element.first << "\t\t" << element.second << endl;
    // }

    // (mp.erase(iterator), mp.erase(key)) <-- O(log n), mp.erase[startIterator, endIterator) <-- O(n)

    // mp.swap(mp2) or swap(mp, mp2)

    // mp.clear()

    // mp.empty()

    // mp.size()

    // mp.max_size()

    // mp.find(key) Returns itr to key if found else returns mp.end() iterator O(log n)

    // mp.count(key) Returns count of key

    // mp.upper_bound(key) returns iterator to next greater key

    // mp.lower_bound(key) returns itr to key if not found returns itr to just the next greater key

    // mp.begin() returns itr to first element, mp.end() returns itr to position after the last element

    // mp.rbegin() returns itr to firs element in reverse order, mp.rend() returns iterator after the last element in reverse order

    // Traversing map using iterator

    // map<string, int>::iterator itr;
    // for(itr = directory.begin(); itr != directory.end(); itr++) {
    //     cout << itr -> first << " - " << itr -> second << endl;
    // }

    // Iterating in reverse
    // map<string, int>::reverse_iterator itr;
    // for(itr = directory.rbegin(); itr != directory.rend(); itr++) {
    //     cout << itr -> first << " - " << itr -> second << endl;
    // }

    // Unordered Map
    // Implemented using Hashing: Insertion, Deletion and Retrieval in O(1)

    // unordered_map<int, string> record;

    // record.insert(make_pair(10, "Aditya"));
    // record[15] = "Raj";

    // for(pair<int, string> pair: record) {
    //     cout << "Roll No - " << pair.first << endl << "Name - " << pair.second << endl;  
    // }

    // Multimap
    // Implemented using BST

    // multimap<int, string> mp;

    // We cannot use mp[1] = "some"; for multimap since [] is not a operator for it 
    // Therefore, we have to use mp.insert(make_pair(1, "some"))

    // advance(itr, steps) used to increment itr with steps 

    // Unordered Multimap
    // Implemented using Hashing O(1) <-- Insertiong, Deletion, Search

    // unordered_multimap<int, int> uom;
    
    return 0;
}