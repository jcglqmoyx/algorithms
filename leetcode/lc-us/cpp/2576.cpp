#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++) {
            while (j < n && nums[i] * 2 > nums[j]) j++;
            if (j < n) res += 2;
        }
        return res;
    }
};