/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Trie {
        int cnt;
        Trie *ne[2];

        Trie() : cnt(0), ne() {}

        void insert(int x) {
            auto node = this;
            for (int i = 14; i >= 0; i--) {
                int j = x >> i & 1;
                if (!node->ne[j]) node->ne[j] = new Trie();
                node = node->ne[j];
                node->cnt++;
            }
        }

        int query(int x, int limit) {
            int res = 0;
            auto node = this;
            for (int i = 14; i >= 0; i--) {
                if (!node) return res;
                int j = x >> i & 1;
                int k = limit >> i & 1;
                if (k) {
                    if (node->ne[j]) res += node->ne[j]->cnt;
                    node = node->ne[j ^ 1];
                } else {
                    node = node->ne[j];
                }
            }
            if (node) res += node->cnt;
            return res;
        }
    };

public:
    int countPairs(vector<int> &nums, int low, int high) {
        auto trie = new Trie();
        int res = 0;
        for (int x: nums) {
            res += trie->query(x, high) - trie->query(x, low - 1);
            trie->insert(x);
        }
        return res;
    }
};
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 20010, M = N * 15;

int son[M][2], idx;
int cnt[M];

void insert(int x) {
    int p = 0;
    for (int i = 14; i >= 0; i--) {
        int j = x >> i & 1;
        if (!son[p][j]) son[p][j] = ++idx;
        p = son[p][j];
        cnt[p]++;
    }
}

int query(int num, int limit) {
    int res = 0;
    int p = 0;
    for (int i = 14; i >= 0; i--) {
        int j = num >> i & 1, k = limit >> i & 1;
        if (k) {
            if (son[p][j]) res += cnt[son[p][j]];
            if (!son[p][1 - j]) return res;
            p = son[p][1 - j];
        } else {
            if (!son[p][j]) return res;
            p = son[p][j];
        }
    }
    res += cnt[p];
    return res;
}

class Solution {
public:
    int countPairs(vector<int> &nums, int low, int high) {
        memset(son, 0, sizeof son), memset(cnt, 0, sizeof cnt);
        int res = 0;
        idx = 0;
        for (int x: nums) {
            res += query(x, high) - query(x, low - 1);
            insert(x);
        }
        return res;
    }
};