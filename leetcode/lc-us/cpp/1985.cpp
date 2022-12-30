#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string> &nums, int k) {
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
        return nums[k - 1];
    }
};