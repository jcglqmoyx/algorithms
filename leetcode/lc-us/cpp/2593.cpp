#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findScore(vector<int> &nums) {
        using PII = pair<int, int>;
        long long res = 0;
        int n = (int) nums.size();
        vector<bool> st(n);
        priority_queue<PII, vector<PII>, greater<>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(nums[i], i);
        }
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int x = t.first, p = t.second;
            if (st[p]) continue;
            res += x, st[p] = true;
            if (p) st[p - 1] = true;
            if (p + 1 < n) st[p + 1] = true;
        }
        return res;
    }
};