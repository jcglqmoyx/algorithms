#include <bits/stdc++.h>

using namespace std;

class Master {
public:
    int guess(string word);
};

class Solution {
    int n;
    vector<vector<int>> f;
    vector<bool> st;

    int get(int i, int cnt) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (st[j]) continue;
            if (f[i][j] == cnt) {
                res++;
            }
        }
        return res;
    }

public:
    void findSecretWord(vector<string> &words, Master &master) {
        n = (int) words.size();
        st = vector<bool>(n);
        f = vector<vector<int>>(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    f[i][j] = f[j][i];
                } else {
                    for (int k = 0; k < 6; k++) {
                        if (words[i][k] == words[j][k]) f[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < 30; i++) {
            int k = -1, mn = INT32_MAX;
            for (int j = 0; j < n; j++) {
                if (!st[j]) {
                    int t = 0;
                    for (int u = 0; u <= 6; u++) {
                        t = max(t, get(j, u));
                    }
                    if (t < mn) {
                        mn = t;
                        k = j;
                    }
                }
            }
            int res = master.guess(words[k]);
            if (res == 6) break;
            st[k] = true;
            for (int j = 0; j < n; j++) {
                if (f[k][j] != res) {
                    st[j] = true;
                }
            }
        }
    }
};