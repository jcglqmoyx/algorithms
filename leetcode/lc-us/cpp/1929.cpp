#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n * 2);
        for (int i = 0; i < n; i++) {
            res[i] = nums[i];
            res[i + n] = nums[i];
        }
        return res;
    }
};