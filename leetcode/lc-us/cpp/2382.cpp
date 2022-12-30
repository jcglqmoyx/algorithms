#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    vector<LL> s;
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries) {
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            s.push_back(0);
            p.push_back(i);
        }
        vector<LL> res(n);
        LL mx = 0;
        for (int i = n - 1; ~i; i--) {
            int idx = removeQueries[i];
            s[idx] = nums[idx];
            for (int j = idx - 1; j <= idx + 1; j += 2) {
                if (j >= 0 && j < n && s[j]) {
                    int pj = find(j);
                    s[idx] += s[pj];
                    p[pj] = idx;
                }
            }
            res[i] = mx;
            mx = max(mx, s[idx]);
        }
        return res;
    }
};