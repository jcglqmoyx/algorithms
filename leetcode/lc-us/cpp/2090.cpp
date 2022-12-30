#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<long long> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i - k >= 0 && i + k < n) res[i] = (int) ((s[i + 1 + k] - s[i - k]) / (k * 2 + 1));
            else res[i] = -1;
        }
        return res;
    }
};