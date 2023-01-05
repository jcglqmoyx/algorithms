/*
#include <bits/stdc++.h>

using namespace std;

struct Tree {
    Tree *ne[2];

    Tree() : ne() {}

    void insert(int num) {
        Tree *t = this;
        for (int i = 30; ~i; i--) {
            int bit = num >> i & 1;
            if (!t->ne[bit]) t->ne[bit] = new Tree();
            t = t->ne[bit];
        }
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        sort(nums.begin(), nums.end());
        int n = (int) queries.size();
        for (int i = 0; i < n; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        vector<int> res(n);
        res.reserve(queries.size());
        auto *tree = new Tree();
        int p = 0;
        for (auto &q: queries) {
            int x = q[0], m = q[1], idx = q[2];
            if (nums.front() > m) {
                res[idx] = -1;
                continue;
            }
            while (p < nums.size() && nums[p] <= m) {
                tree->insert(nums[p]);
                p++;
            }
            auto t = tree;
            int sum = 0;
            for (int i = 30; ~i; i--) {
                int bit = (x >> i) & 1;
                int j = bit ^ 1;
                if (t->ne[j]) {
                    t = t->ne[j];
                    sum += 1 << i;
                } else if (t->ne[bit]) {
                    t = t->ne[bit];
                } else {
                    break;
                }
            }
            res[idx] = sum;
        }
        return res;
    }
};
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 31;

int son[M][2], idx;
int mn[M];

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        mn[p] = min(mn[p], x);
    }
}

int query(int num, int limit) {
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int j = num >> i & 1;
        if (son[p][j ^ 1]) {
            if (mn[son[p][j ^ 1]] <= limit) {
                res += 1 << i;
                p = son[p][j ^ 1];
            } else {
                if (!son[p][j]) return -1;
                p = son[p][j];
            }
        } else {
            if (son[p][j] && mn[son[p][j]] <= limit) {
                p = son[p][j];
            }
        }
    }
    return res;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        memset(son, 0, sizeof son), memset(mn, 0x3f, sizeof mn), idx = 0;
        for (int x: nums) insert(x);
        int n = (int) queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            auto &q = queries[i];
            int x = q[0], m = q[1];
            res[i] = query(x, m);
        }
        return res;
    }
};