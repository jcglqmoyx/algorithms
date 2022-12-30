#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        int cnt = 0;
        int n = intervals.size();
        vector<bool> removed(n);
        for (int i = 0, j = 1; i < n && j < n;) {
            while (j < n && intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                cnt++;
                removed[j] = true;
                j++;
            }
            i++;
            while (i < n && removed[i]) i++;
            if (i == j) j++;
        }
        return n - cnt;
    }
};