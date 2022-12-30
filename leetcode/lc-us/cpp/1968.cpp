#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<int> result;
        result.reserve(n);
        int j = n / 2, i = 0;
        while (result.size() < n) {
            result.push_back(nums[j++]);
            if (result.size() == n) break;
            result.push_back(nums[i++]);
        }
        return result;
    }
};