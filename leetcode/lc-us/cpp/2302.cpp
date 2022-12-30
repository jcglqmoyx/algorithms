#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        using LL = long long;
        int n = (int) nums.size();
        LL s[n + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        LL res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            while ((s[j + 1] - s[i]) * (j - i + 1) >= k) i++;
            res += j - i + 1;
        }
        return res;
    }
};