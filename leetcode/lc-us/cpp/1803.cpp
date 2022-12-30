#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Trie {
        int cnt;
        Trie *next[2];

        Trie() : cnt(0), next() {}

        void insert(int x) {
            auto node = this;
            for (int i = 14; i >= 0; i--) {
                int j = x >> i & 1;
                if (!node->next[j]) node->next[j] = new Trie();
                node = node->next[j];
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
                    if (node->next[j]) res += node->next[j]->cnt;
                    node = node->next[1 ^ j];
                } else {
                    node = node->next[j];
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