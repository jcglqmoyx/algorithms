#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
        unordered_map<int, int> M;
        for (auto it = operations.rbegin(); it != operations.rend(); it++) {
            int x = (*it)[0], y = (*it)[1];
            if (M.count(y)) M[x] = M[y];
            else M[x] = y;
        }
        for (int &x: nums) {
            if (M.count(x)) x = M[x];
            else continue;
        }
        return nums;
    }
};