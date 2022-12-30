#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string encode(string s) {
        int n = (int) s.size();
        f.resize(n, vector<string>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                f[i][j] = get(s, i, j);
                if (len > 4) {
                    for (int k = i; k < j; k++) {
                        if (f[i][j].size() > f[i][k].size() + f[k + 1][j].size()) {
                            f[i][j] = f[i][k] + f[k + 1][j];
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }

private:
    vector<vector<string>> f;

    string get(string &s, int i, int j) {
        int len = j - i + 1;
        string t = s.substr(i, len);
        if (len <= 4) return t;
        auto p = (t + t).find(t, 1);
        if (p != t.size()) {
            auto cnt = t.size() / p;
            return to_string(cnt) + '[' + f[i][i + p - 1] + ']';
        }
        return t;
    }
};