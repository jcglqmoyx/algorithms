#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> s1(n + 1), s2(n + 1);
        for (int i = 1; i <= n; i++) {
            s1[i] = s1[i - 1], s2[i] = s2[i - 1];
            if (i & 1) s1[i] += nums[i - 1];
            else s2[i] += nums[i - 1];
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int odd = s1[i - 1] + s2[n] - s2[i];
            int even = s2[i - 1] + s1[n] - s1[i];
            if (odd == even) res++;
        }
        return res;
    }
};