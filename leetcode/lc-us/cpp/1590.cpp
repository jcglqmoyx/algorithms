#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int sum = 0;
        for (int x: nums) sum = (sum + x) % p;
        if (!sum) return 0;
        int n = (int) nums.size(), res = n, cur = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int t = (cur - sum + p) % p;
            if (hash.count(t)) res = min(res, i - hash[t]);
            hash[cur] = i;
        }
        return res == n ? -1 : res;
    }
};