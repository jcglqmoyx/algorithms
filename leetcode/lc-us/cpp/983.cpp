#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = (int) days.size();
        vector<int> f(n + 1, 1e8);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int d = days[i - 1];
            int j = i;
            while (j >= 1 && d - days[j - 1] < 1) j--;
            f[i] = min(f[i], f[j] + costs[0]);
            while (j >= 1 && d - days[j - 1] < 7) j--;
            f[i] = min(f[i], f[j] + costs[1]);
            while (j >= 1 && d - days[j - 1] < 30) j--;
            f[i] = min(f[i], f[j] + costs[2]);
        }
        return f[n];
    }
};