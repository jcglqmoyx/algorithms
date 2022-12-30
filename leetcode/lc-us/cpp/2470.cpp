#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long get_lcm(long long x, long long y) {
        return x * y / __gcd(x, y);
    }

public:
    int subarrayLCM(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long long lcm = nums[i];
            for (int j = i; j < n; j++) {
                lcm = get_lcm(lcm, nums[j]);
                if (lcm == k) cnt++;
                if (lcm > k) break;
            }
        }
        return cnt;
    }
};