#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>> &events) {
        int n = (int) events.size();
        sort(events.begin(), events.end());
        vector<int> memo(n);
        int mx = 0;
        for (int i = n - 1; ~i; i--) mx = max(mx, events[i].back()), memo[i] = mx;
        int res = events.back().back();
        for (int i = 0; i < n - 1; i++) {
            res = max(res, events[i].back());
            int l = i + 1, r = n - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (events[mid].front() > events[i][1]) r = mid;
                else l = mid + 1;
            }
            if (events[l].front() > events[i][1]) res = max(res, events[i].back() + memo[l]);
        }
        return res;
    }
};