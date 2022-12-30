#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int get(string &a, string &b) {
        for (int i = (int) min(a.size(), b.size()); i; i--) {
            if (a.substr(a.size() - i) == b.substr(0, i)) return i;
        }
        return 0;
    }

public:
    string shortestSuperstring(vector<string> &words) {
        int n = (int) words.size();
        int overlap[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                overlap[i][j] = get(words[i], words[j]);
            }
        }
        const int INF = 0x3f3f3f3f;
        int f[1 << n][n];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; i++) f[1 << i][i] = (int) words[i].size();
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][j] == INF) continue;
                for (int k = 0; k < n; k++) {
                    if (i >> k & 1) continue;
                    int st = i | 1 << k;
                    f[st][k] = min(f[st][k], f[i][j] + (int) words[k].size() - overlap[j][k]);
                }
            }
        }
        int i = (1 << n) - 1, j = 0;
        for (int k = 1; k < n; k++) {
            if (f[i][k] < f[i][j]) {
                j = k;
            }
        }
        vector<int> q;
        for (int u = 0; u < n; u++) {
            q.push_back(j);
            for (int k = 0; k < n; k++) {
                if (f[i ^ 1 << j][k] + (int) words[j].size() - overlap[k][j] == f[i][j]) {
                    i ^= 1 << j;
                    j = k;
                    break;
                }
            }
        }
        reverse(q.begin(), q.end());
        string res = words[q[0]];
        for (int k = 1; k < n; k++) {
            res += words[q[k]].substr(overlap[q[k - 1]][q[k]]);
        }
        return res;
    }
};