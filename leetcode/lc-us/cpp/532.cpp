#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        for (int num: nums) cnt[num]++;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int res = 0;
        if (k == 0) {
            for (int e: nums) if (cnt[e] > 1) res++;
        } else {
            for (int e: nums) if (cnt.find(e + k) != cnt.end()) res++;
        }
        return res;
    }
};