#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, res;
    int st[15];

    void dfs(vector<vector<int>> &statements, int u) {
        if (u == n) {
            bool flag = true;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (st[i] == 1) {
                    for (int j = 0; j < n; j++) {
                        if (statements[i][j] < 2 && statements[i][j] != st[j]) {
                            flag = false;
                            break;
                        }
                    }
                    cnt++;
                }
            }
            if (flag) res = max(res, cnt);
            return;
        }
        st[u] = 0;
        dfs(statements, u + 1);
        st[u] = 1;
        dfs(statements, u + 1);
    }

public:
    int maximumGood(vector<vector<int>> &statements) {
        n = (int) statements.size(), res = 0;
        dfs(statements, 0);
        return res;
    }
};