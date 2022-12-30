#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        int n = (int) buses.size(), m = (int) passengers.size();
        sort(buses.begin(), buses.end()), sort(passengers.begin(), passengers.end());
        vector<int> v;
        int i = 0, j = 0;
        for (; i < n; i++) {
            int t = capacity;
            while (t) {
                if (j < m && passengers[j] <= buses[i]) {
                    v.push_back(passengers[j]);
                    j++;
                    t--;
                } else break;
            }
            if (t && i == n - 1 && !v.empty() && v.back() < buses[i]) {
                v.push_back(buses.back() + 1);
            }
        }
        j--;
        if (j < 0) {
            return buses.back();
        }
        int len = (int) v.size();
        for (int u = len - 1; u >= 0; u--) {
            if (u > 0 && v[u - 1] + 1 != v[u]) {
                return v[u] - 1;
            }
        }
        return v[0] - 1;
    }
};