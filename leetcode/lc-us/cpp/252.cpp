#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] < b[0]) return true;
        else if (a[0] > b[0]) return false;
        else return a[1] < b[1];
    }

public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.empty() || intervals.size() == 1) return true;
        sort(intervals.begin(), intervals.end(), &cmp);
        int high = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (high > intervals[i][0]) return false;
            high = intervals[i][1];
        }
        return true;
    }
};