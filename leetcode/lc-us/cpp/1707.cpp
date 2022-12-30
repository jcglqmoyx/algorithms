#include <bits/stdc++.h>

using namespace std;

struct Tree {
    Tree *next[2];

    Tree() : next() {}

    void insert(int num) {
        Tree *t = this;
        for (int i = 30; ~i; i--) {
            int bit = num >> i & 1;
            if (!t->next[bit]) t->next[bit] = new Tree();
            t = t->next[bit];
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
                if (t->next[j]) {
                    t = t->next[j];
                    sum += 1 << i;
                } else if (t->next[bit]) {
                    t = t->next[bit];
                } else {
                    break;
                }
            }
            res[idx] = sum;
        }
        return res;
    }
};