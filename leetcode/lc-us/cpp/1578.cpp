#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string s, vector<int> &cost) {
        int res = 0, n = (int) s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                int j = i + 1, sum = cost[i], mx = cost[i];
                while (j < n && s[j] == s[j - 1]) {
                    sum += cost[j];
                    mx = max(mx, cost[j]);
                    j++;
                }
                i = j - 1;
                res += sum - mx;
            }
        }
        return res;
    }
};