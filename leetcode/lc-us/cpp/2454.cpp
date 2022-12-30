#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = (int) nums.size();
        stack<int> stk;
        vector<int> res(n, -1);
        vector<vector<pair<int, int>>> v(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                v[stk.top()].push_back({nums[i], i});
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            if (!v[i].empty()) {
                sort(v[i].begin(), v[i].end(), greater<>());
                while (!stk.empty() && !v[i].empty()) {
                    while (!stk.empty() && nums[stk.top()] <= v[i].back().first) {
                        stk.pop();
                    }
                    if (!stk.empty()) {
                        res[v[i].back().second] = nums[stk.top()];
                        v[i].pop_back();
                    }
                }
            }
            stk.push(i);
        }
        return res;
    }
};