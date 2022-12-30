#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSolvable(vector<string> &words, string result) {
        int max_len = 0;
        for (auto &w: words) {
            reverse(w.begin(), w.end());
            max_len = max(max_len, (int) w.size());
        }
        n = (int) result.size();
        if (max_len > n || max_len + 1 < n) return false;

        init();

        reverse(result.begin(), result.end());

        return dfs(words, result, 0, 0, 0);
    }

private:
    int n;
    int p[123];
    bool st[10];

    void init() {
        memset(p, -1, sizeof p);
        memset(st, false, sizeof st);
    }

    bool dfs(vector<string> &words, string &result, int col, int row, int sum) {
        if (col == result.size()) {
            return !sum;
        }
        if (row == words.size()) {
            char c = result[col];
            if (p[c] == -1) {
                for (int i = (n > 1 && col == n - 1); i <= 9; i++) {
                    if (!st[i] && sum % 10 == i) {
                        st[i] = true;
                        p[c] = i;
                        if (dfs(words, result, col + 1, 0, sum / 10)) {
                            return true;
                        }
                        p[c] = -1;
                        st[i] = false;
                    }
                }
            } else {
                if (sum % 10 != p[c]) {
                    return false;
                }
                if (!(result.size() > 1 && !p[result[n - 1]]) && dfs(words, result, col + 1, 0, sum / 10)) {
                    return true;
                }
            }
        } else {
            if (col >= words[row].size()) {
                if (dfs(words, result, col, row + 1, sum)) return true;
            } else {
                char c = words[row][col];
                if (p[c] == -1) {
                    for (int i = (words[row].size() > 1 && col == (int) words[row].size() - 1); i <= 9; i++) {
                        if (!st[i]) {
                            st[i] = true;
                            p[c] = i;
                            if (dfs(words, result, col, row + 1, sum + i)) {
                                return true;
                            }
                            p[c] = -1;
                            st[i] = false;
                        }
                    }
                } else {
                    if (!(words[row].size() > 1 && !p[words[row][words[row].size() - 1]]) &&
                        dfs(words, result, col, row + 1, sum + p[c])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};