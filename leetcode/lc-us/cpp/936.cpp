#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = (int) stamp.size(), m = (int) target.size();
        vector<int> res;
        while (true) {
            bool flag = false;
            for (int i = 0; i + n - 1 < m; i++) {
                if (match(stamp, target, i)) {
                    flag = true;
                    res.push_back(i);
                    for (int j = i; j < i + stamp.size(); j++) {
                        target[j] = '*';
                    }
                }
            }
            if (!flag) break;
        }
        if (target != string(m, '*')) return {};
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool match(string &s, string &t, int u) {
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i + u]) {
                if (t[i + u] != '*') flag = true;
                continue;
            }
            if (t[i + u] != '*') return false;
        }
        return flag;
    }
};