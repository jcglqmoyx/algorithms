#include <bits/stdc++.h>

using namespace std;

class SummaryRanges {
    const int INF = 1e9;
    set<pair<int, int>> intervals;

public:
    SummaryRanges() {
        intervals.insert({-INF, -INF});
        intervals.insert({INF, INF});
    }

    void addNum(int val) {
        auto r = intervals.upper_bound({val, INF});
        auto l = r;
        l--;
        if (val == l->second + 1 && val == r->first - 1) {
            intervals.insert({l->first, r->second});
            intervals.erase(l);
            intervals.erase(r);
        } else if (val == l->second + 1) {
            intervals.insert({l->first, val});
            intervals.erase(l);
        } else if (val == r->first - 1) {
            intervals.insert({val, r->second});
            intervals.erase(r);
        } else if (val > l->second + 1 && val < r->first - 1) {
            intervals.insert({val, val});
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (pair<int, int> interval: intervals) {
            if (interval.first != INF && interval.first != -INF) {
                res.push_back({interval.first, interval.second});
            }
        }
        return res;
    }
};

/*
#include <bits/stdc++.h>

using namespace std;

class SummaryRanges {
    set<pair<int, int>> S;
public:
    SummaryRanges() {
    }

    void addNum(int value) {
        S.insert({value, value});
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start = (*S.begin()).first, end = (*S.begin()).second;
        for (auto &v: S) {
            if (v.first > end + 1) res.push_back({start, end}), start = v.first, end = v.second;
            else end = max(end, v.second);
        }
        res.push_back({start, end});
        S.clear();
        for (auto &e: res) {
            S.insert({e[0], e[1]});
        }
        return res;
    }
};
 */