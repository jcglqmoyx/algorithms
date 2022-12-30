#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int> &nums, int key) {
        int res = 0, max_cnt = 0, n = (int) nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == key) {
                cnt[nums[i + 1]]++;
            }
        }
        for (auto[k, v]: cnt) {
            if (v > max_cnt) {
                max_cnt = v;
                res = k;
            }
        }
        return res;
    }
};