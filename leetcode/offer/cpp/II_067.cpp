#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie *next[2];

    Trie() : next() {}

    void insert(int num) {
        auto trie = this;
        for (int i = 30; ~i; i--) {
            int digit = (num >> i) & 1;
            if (!trie->next[digit]) trie->next[digit] = new Trie;
            trie = trie->next[digit];
        }
    }

    int query(int x) {
        int num = 0;
        auto trie = this;
        for (int i = 30; ~i; i--) {
            int digit = (x >> i) & 1;
            if (trie->next[digit ^ 1]) {
                num = (num << 1) + digit ^ 1;
                trie = trie->next[digit ^ 1];
            } else {
                num = (num << 1) + digit;
                trie = trie->next[digit];
            }
        }
        return num ^ x;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int res = 0;
        auto trie = new Trie;
        for (int num: nums) trie->insert(num);
        for (int num: nums) res = max(res, trie->query(num));
        return res;
    }
};