/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
        n = (int) students[0].size(), m = (int) students.size();
        stu = students, men = mentors;
        init();
        st.resize(m, false);
        dfs(0, 0);
        return res;
    }

private:
    int res = 0;
    int n, m;
    vector<vector<int>> stu, men, score;
    vector<bool> st;

    void init() {
        score.resize(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int s = 0;
                for (int k = 0; k < n; k++) {
                    if (stu[i][k] == men[j][k]) {
                        s++;
                    }
                }
                score[i][j] = s;
            }
        }
    }

    void dfs(int idx, int s) {
        if (idx == m) {
            res = max(res, s);
            return;
        }
        for (int i = 0; i < m; i++) {
            if (st[i]) continue;
            st[i] = true;
            dfs(idx + 1, s + this->score[idx][i]);
            st[i] = false;
        }
    }
};
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
        int n = (int) students.size(), m = (int) students[0].size();
        int vs[n], vm[n];
        memset(vs, 0, sizeof vs);
        memset(vm, 0, sizeof vm);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (students[i][j]) mask |= 1 << j;
            }
            vs[i] = mask;
        }
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (mentors[i][j]) mask |= 1 << j;
            }
            vm[i] = mask;
        }
        int memo[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = __builtin_popcount(~(vs[i] ^ vm[j])) - (32 - m);
            }
        }
        int f[1 << n];
        memset(f, 0, sizeof f);
        for (int i = 1; i < 1 << n; i++) {
            int c = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    f[i] = max(f[i], f[i ^ (1 << j)] + memo[c - 1][j]);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};