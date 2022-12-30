#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums) {
        long long res = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1]) j++;
            long long len = j - i;
            res += len * (len + 1) / 2;
            i = j - 1;
        }
        return res;
    }
};