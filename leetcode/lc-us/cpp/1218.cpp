#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int res = 1;
        unordered_map<int, int> hash;
        for (int x: arr) {
            int y = x - difference;
            if (hash.count(y)) res = max(res, hash[y] + 1), hash[x] = hash[y] + 1;
            else hash[x] = 1;
        }
        return res;
    }
};