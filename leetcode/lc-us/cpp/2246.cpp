#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int res;
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    int dfs(string &s, int u) {
        int first = -1, second = -1;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (s[j] == s[u]) {
                res = max(res, dfs(s, j));
                continue;
            }
            int len = dfs(s, j);
            if (len > second) {
                if (len > first) {
                    second = first;
                    first = len;
                } else {
                    second = len;
                }
            }
        }
        if (first == -1) {
            res = max(res, 1);
            return 1;
        }
        res = max(res, first + 1);
        if (second != -1) {
            res = max(res, first + second + 1);
        }
        return first + 1;
    }

public:
    int longestPath(vector<int> &parent, string s) {
        if (s.size() == 1) return 1;
        res = 0;
        memset(h, -1, sizeof h), memset(ne, 0, sizeof ne), idx = 0;
        int n = (int) parent.size();
        for (int i = 0; i < n; i++) {
            if (parent[i] >= 0) {
                add(parent[i], i);
            }
        }
        dfs(s, 0);
        return res;
    }
};