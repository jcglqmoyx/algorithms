#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int x = intervals[0][1] - 1, y = intervals[0][1];
        int res = 2;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > y) {
                res += 2;
                x = intervals[i][1] - 1, y = intervals[i][1];
            } else if (intervals[i][0] > x) {
                x = y, y = intervals[i][1];
                res++;
            }
        }
        return res;
    }
};