#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        using LL = long long;
        int n = (int) nums.size();
        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (j < n && nums[j] == 0) j++;
                LL len = j - i;
                res += len * (len + 1) / 2;
                i = j - 1;
            }
        }
        return res;
    }
};