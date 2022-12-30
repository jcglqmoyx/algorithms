#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarrayGCD(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % k) continue;
            if (nums[i] == k) res++;
            int g = nums[i];
            bool flag = false;
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == k) res++, flag = true;
                else if (flag) break;
            }
        }
        return res;
    }
};