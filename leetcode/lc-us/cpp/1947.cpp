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