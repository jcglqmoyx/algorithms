#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        int n = (int) nums.size();
        int a[n];
        for (int i = 0; i < n; i++) a[i] = i;
        vector<string> ans(n);
        sort(a, a + n, [&](const int x, const int y) {
            return nums[x] > nums[y];
        });
        if (n > 0) ans[a[0]] = "Gold Medal";
        if (n > 1) ans[a[1]] = "Silver Medal";
        if (n > 2) ans[a[2]] = "Bronze Medal";
        for (int i = 3; i < n; i++) ans[a[i]] = to_string(i + 1);
        return ans;
    }
};