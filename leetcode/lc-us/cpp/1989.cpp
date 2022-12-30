#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int catchMaximumAmountofPeople(vector<int> &team, int dist) {
        int n = (int) team.size(), res = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (team[i]) {
                int start = max(0, i - dist), end = min(n - 1, i + dist);
                if (j > end) continue;
                while (j < start) j++;
                while (j <= end && team[j]) j++;
                if (j <= end) res++, j++;
            }
        }
        return res;
    }
};