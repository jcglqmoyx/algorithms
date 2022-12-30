#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> points, p, w;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    int get(int x) {
        return lower_bound(points.begin(), points.end(), x) - points.begin();
    }

public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        for (auto &interval: intervals) points.push_back(interval[0]), points.push_back(interval[1]);
        for (int q: queries) points.push_back(q);
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int n = (int) points.size();
        p.resize(n + 1), w.resize(n + 1, -1);
        for (int i = 0; i < n + 1; i++) p[i] = i;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        for (auto &interval: intervals) {
            int l = get(interval[0]), r = get(interval[1]), len = interval[1] - interval[0] + 1;
            while (find(l) <= r) {
                l = find(l);
                w[l] = len;
                p[l] = l + 1;
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for (int q: queries) res.push_back(w[get(q)]);
        return res;
    }
};