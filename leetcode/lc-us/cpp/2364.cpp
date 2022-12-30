#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int> &nums) {
        auto n = (long long) nums.size();
        long long res = n * (n - 1) / 2;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            res -= map[i - nums[i]];
            map[i - nums[i]]++;
        }
        return res;
    }
};