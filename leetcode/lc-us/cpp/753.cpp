#include <bits/stdc++.h>

using namespace std;

class Solution {
    int _k;
    unordered_set<string> S;
    string ans;

    void dfs(string u) {
        for (int i = 0; i < _k; i++) {
            auto v = u + to_string(i);
            if (!S.count(v)) {
                S.insert(v);
                dfs(v.substr(1));
                ans += to_string(i);
            }
        }
    }

public:
    string crackSafe(int n, int k) {
        _k = k;
        string start(n - 1, '0');
        dfs(start);
        return ans + start;
    }
};