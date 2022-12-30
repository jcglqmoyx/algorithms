#include <bits/stdc++.h>

using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<vector<int>> v;
        for (auto &s: schedule) {
            for (auto &interval: s) {
                int start = interval.start, end = interval.end;
                v.push_back({start, end});
            }
        }
        sort(v.begin(), v.end());
        int n = (int) v.size();
        for (int i = 0; i < n; i++) {
            int right_most = v[i][1];
            int j = i + 1;
            while (j < n && v[j][0] <= right_most) {
                right_most = max(right_most, v[j][1]);
                j++;
            }
            if (j < n) res.emplace_back(right_most, v[j][0]);
            i = j - 1;
        }
        return res;
    }
};