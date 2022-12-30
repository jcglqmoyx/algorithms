#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int n = (int) nums.size(), mx = 0;
        vector<int> f(1 << n);
        unordered_map<int, int> hash;
        for (int i = 0; i < 1 << n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) sum = sum | nums[j];
            }
            hash[sum]++;
            mx = max(mx, sum);
        }
        return hash[mx];
    }
};