#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        using TII = tuple<int, int, int>;
        int n = (int) startTime.size();
        vector<TII> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return get<1>(a) < get<1>(b);
        });
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int start = get<0>(v[i - 1]);
            int p = get<2>(v[i - 1]);
            f[i] = max(f[i - 1], p);
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (get<1>(v[mid - 1]) > start) r = mid - 1;
                else l = mid;
            }
            f[i] = max(f[i], f[l] + p);
        }
        return f[n];
    }
};