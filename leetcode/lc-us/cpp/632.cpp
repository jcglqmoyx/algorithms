#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> heap;
        int mx = INT32_MIN;
        for (int i = 0; i < (int) nums.size(); i++) {
            heap.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int x = t[0], row = t[1], col = t[2];
            if (res.empty() || res[1] - res[0] > mx - x) {
                res = {x, mx};
            }
            if (col + 1 < (int) nums[row].size()) {
                heap.push({nums[row][col + 1], row, col + 1});
                mx = max(mx, nums[row][col + 1]);
            } else {
                break;
            }
        }
        return res;
    }
};