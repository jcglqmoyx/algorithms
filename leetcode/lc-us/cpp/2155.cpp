#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &nums) {
        vector<int> res;
        int sum = 0, mx = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (nums[i]) {
                sum--;
            } else {
                sum++;
            }
            if (sum > mx) {
                res = {i + 1};
                mx = sum;
            } else if (sum == mx) {
                res.push_back(i + 1);
            }
        }
        if (mx == 0) res.push_back(0);
        return res;
    }
};