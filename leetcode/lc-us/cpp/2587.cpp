#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int res = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum <= 0) break;
            res++;
        }
        return res;
    }
};