#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < arr2.size(); i++) hash[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (hash.count(a) && hash.count(b)) return hash[a] < hash[b];
            else if (hash.count(a)) return true;
            else if (hash.count(b)) return false;
            else return a < b;
        });
        return arr1;
    }
};