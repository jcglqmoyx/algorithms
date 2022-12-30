#include <bits/stdc++.h>

using namespace std;

static const int N = 20;

int h[N], w[N], e[N], ne[N], idx;

class Solution {
    int res = 0;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u, int sum) {
        if (h[u] == -1) {
            res += sum;
        }
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            dfs(j, sum + w[j]);
        }
    }

public:
    int pathSum(vector<int> &nums) {
        memset(h, -1, sizeof h), idx = 0;
        for (int i: nums) {
            int x = i / 100, y = i / 10 % 10, z = i % 10;
            int num = (1 << (x - 1)) + y - 1;
            w[num] = z;
            add(num >> 1, num);
        }
        dfs(1, w[1]);
        return res;
    }
};