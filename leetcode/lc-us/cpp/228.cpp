#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> summary;
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && (long) nums[j] - (long) nums[i] == j - i) j++;
            if (nums[i] == nums[j - 1]) summary.push_back(to_string(nums[i]));
            else summary.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            i = j;
        }
        return summary;
    }
};