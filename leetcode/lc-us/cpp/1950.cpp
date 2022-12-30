#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMaximums(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n), len(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (s.empty()) len[i] = -1;
            else len[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (s.empty()) len[i] = n - len[i] - 1;
            else len[i] = s.top() - len[i] - 1;
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            int idx = len[i] - 1;
            res[idx] = max(res[idx], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            res[i] = max(res[i], res[i + 1]);
        }
        return res;
    }
};