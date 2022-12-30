#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        priority_queue<int, vector<int>, greater<>> q;
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for (auto &interval: intervals) {
            if (q.empty()) {
                q.push(interval[1]);
            } else {
                int end = q.top();
                if (interval[0] >= end) {
                    q.pop();
                }
                q.push(interval[1]);
            }
            res = max(res, (int) q.size());
        }
        return res;
    }
};