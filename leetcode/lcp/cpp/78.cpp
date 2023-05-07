#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rampartDefensiveLine(vector<vector<int>> &rampart) {
        auto check = [&](int m) {
            int last = rampart[0][1];
            for (int i = 1; i + 1 < rampart.size(); i++) {
                int L = rampart[i][0] - last, R = rampart[i + 1][0] - rampart[i][1];
                if (L + R < m) return false;
                last = rampart[i][1];
                if (m > L) last += m - L;
            }
            return true;
        };
        int l = 0, r = 1e8;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (check(m)) l = m;
            else r = m - 1;
        }
        return l;
    }
};