#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    static bool check(LL a, LL b, LL c, LL d) {
        if (b < c || d < a) return false;
        return true;
    }

public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        int n = candiesCount.size();
        vector<LL> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + candiesCount[i - 1];
        }
        vector<bool> answer;
        answer.reserve(queries.size());
        for (auto &q: queries) {
            int t = q[0], d = q[1], c = q[2];
            LL l = d + 1, r = (LL) (d + 1) * c;
            answer.push_back(check(l, r, s[t] + 1, s[t + 1]));
        }
        return answer;
    }
};