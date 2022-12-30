#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        using LL = long long;
        LL tot = 0;
        for (int num: nums) tot += num;
        LL remainder = tot % p;
        if (!remainder) return 0;
        int n = (int) nums.size();
        int res = n;
        unordered_map<LL, int> hash;
        hash[0] = -1;
        LL sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            LL r = sum % p;
            hash[r] = i;
            LL last = (r + p - remainder) % p;
            if (hash.count(last)) {
                res = min(res, i - hash[last]);
            }
        }
        return res == n ? -1 : res;
    }
};