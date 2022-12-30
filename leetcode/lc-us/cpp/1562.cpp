#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLatestStep(vector<int> &arr, int m) {
        int n = (int) arr.size(), res = -1;
        vector<pair<int, int>> intervals(n + 2, {-1, -1});
        int cnt = 0;
        for (int i = 1; i <= arr.size(); i++) {
            int x = arr[i - 1];
            if (intervals[x - 1].first == -1 && intervals[x + 1].first == -1) {
                if (m == 1) cnt++;
                intervals[x] = {x, x};
            } else if (intervals[x - 1].first != -1 && intervals[x + 1].first == -1) {
                int l = intervals[x - 1].first;
                int len = x - l + 1;
                if (len == m) cnt++;
                else if (intervals[x - 1].second - l + 1 == m) cnt--;
                intervals[l].second = x;
                intervals[x] = {l, x};
            } else if (intervals[x - 1].first == -1 && intervals[x + 1].first != -1) {
                int r = intervals[x + 1].second;
                int len = r - x + 1;
                if (len == m) cnt++;
                else if (r - intervals[x + 1].first + 1 == m) cnt--;
                intervals[r].first = x;
                intervals[x] = {x, r};
            } else {
                int l = intervals[x - 1].first, r = intervals[x + 1].second;
                int len = r - l + 1;
                if (len == m) cnt++;
                if (intervals[x - 1].second - l + 1 == m) cnt--;
                if (r - intervals[x + 1].first + 1 == m) cnt--;
                intervals[l].second = r, intervals[r].first = l;
            }
            if (cnt) res = i;
        }
        return res;
    }
};