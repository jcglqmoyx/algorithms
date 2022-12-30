#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDifference(vector<int> &a, vector<int> &b) {
        long min_diff = INT32_MAX;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        int m = (int) a.size(), n = (int) b.size();
        while (i < m && j < n) {
            long diff = abs((long) a[i] - (long) b[j]);
            min_diff = min(min_diff, diff);
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] >= b[j]) {
                j++;
            } else {
                return 0;
            }
        }
        return (int) min_diff;
    }
};