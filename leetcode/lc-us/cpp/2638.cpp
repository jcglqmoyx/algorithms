#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> map;
        for (int x: nums) map[x % k].push_back(x);
        long long res = 1;
        for (auto &[_, v]: map) {
            long long f0 = 1, f1 = 1;
            int last = v[0];
            for (int i = 1; i < v.size(); i++) {
                int x = v[i];
                long long g0 = f0 + f1, g1 = f0 + f1;
                if (x - last == k) g1 = f0;
                f0 = g0, f1 = g1;
                last = x;
            }
            res *= f0 + f1;
        }
        return res;
    }
};