#include<bits/stdc++.h>

using namespace std;

const int N = 310;

int n;
bool infected[N];
int h[N], e[N * N >> 1], ne[N * N >> 1], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
private:
    int work(vector<vector<int>> &graph, vector<int> &initial, int pos) {
        memset(h, -1, sizeof h), memset(ne, 0, sizeof ne), idx = 0;
        for (int row = 0; row < n; row++) {
            if (row == pos) continue;
            for (int col = 0; col < n; col++) {
                if (col == pos) continue;
                if (graph[row][col]) {
                    add(row, col), add(col, row);
                }
            }
        }
        int res = 0;
        bool st[n];
        memset(st, false, sizeof st);
        for (int x: initial) {
            queue<int> q;
            q.push(x);
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (int i = h[t]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (infected[j] || st[j]) continue;
                    st[j] = true;
                    res++;
                    q.push(j);
                }
            }
        }
        return res;
    }

public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        n = (int) graph.size();
        memset(infected, false, sizeof infected);
        for (int pos: initial) infected[pos] = true;
        int res = 0, mn = 1e8;
        for (int pos: initial) {
            int t = work(graph, initial, pos);
            if (t < mn) mn = t, res = pos;
            else if (t == mn && pos < res) res = pos;
        }
        return res;
    }
};