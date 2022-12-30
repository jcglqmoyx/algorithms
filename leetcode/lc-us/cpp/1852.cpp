#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<int> res(n - k + 1);
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            if (i >= k) {
                cnt[nums[i - k]]--;
                if (cnt[nums[i - k]] == 0) cnt.erase(nums[i - k]);
            }
            if (i - k + 1 >= 0) res[i - k + 1] = (int) cnt.size();
        }
        return res;
    }
};