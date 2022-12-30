#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> elementInNums(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int) nums.size(), m = (int) queries.size();
        vector<int> res(m);
        int i = 0;
        for (auto &q: queries) {
            int time = q[0], idx = q[1];
            int j = time / n;
            if (j & 1) {
                int len = time % n;
                if (len <= idx) res[i] = -1;
                else res[i] = nums[idx];
            } else {
                int len = n - time % n;
                if (len <= idx) res[i] = -1;
                else res[i] = nums[idx + n - len];
            }
            i++;
        }
        return res;
    }
};