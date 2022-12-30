#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int h[N], e[N], ne[N], idx;
bool st[N];
int s[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int> &parent, vector<int> &value) {
        memset(h, -1, sizeof h);
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(st, false, sizeof st);
        memset(s, 0, sizeof s);
        idx = 0;

        for (int i = 1; i < nodes; i++) {
            add(parent[i], i);
        }
        get(value, 0);
        memset(st, false, sizeof st);
        for (int i = 0; i < nodes; i++) {
            if (!st[i] && s[i] == 0) clear(i);
        }
        int cnt = 0;
        for (int i = 0; i < nodes; i++) {
            if (!st[i]) cnt++;
        }
        return cnt;
    }

private:
    int get(vector<int> &value, int u) {
        if (st[u]) return s[u];
        st[u] = true;
        int sum = value[u];
        for (int i = h[u]; i != -1; i = ne[i]) {
            sum += get(value, e[i]);
        }
        s[u] = sum;
        return sum;
    }

    void clear(int u) {
        st[u] = true;
        for (int i = h[u]; i != -1; i = ne[i]) {
            clear(e[i]);
        }
    }
};