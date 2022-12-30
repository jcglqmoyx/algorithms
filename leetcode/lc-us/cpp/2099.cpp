#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        vector<int> res;
        vector<int> tmp = nums;
        unordered_map<int, int> cnt;
        sort(tmp.begin(), tmp.end(), greater<>());
        for (int i = 0; i < k; i++) {
            cnt[tmp[i]]++;
        }
        for (int x: nums) {
            if (cnt.count(x) && cnt[x]) {
                res.push_back(x);
                cnt[x]--;
            }
        }
        return res;
    }
};