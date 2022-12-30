#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {
        int n = 2052;
        vector<int> diff(n);
        for (auto &log: logs) {
            diff[log[0]]++;
            diff[log[1]]--;
        }
        vector<int> cnt(n);
        int mx = 0;
        for (int year = 1950; year <= 2050; year++) {
            diff[year] += diff[year - 1];
            cnt[year] += diff[year];
            mx = max(mx, cnt[year]);
        }
        int res = 1950;
        for (int year = 1950; year <= 2050; year++) {
            if (cnt[year] == mx) {
                res = year;
                break;
            }
        }
        return res;
    }
};