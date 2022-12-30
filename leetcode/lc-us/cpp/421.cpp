#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie *next[2];

    Trie() : next() {}

    void insert(int x) {
        Trie *trie = this;
        for (int i = 30; ~i; i--) {
            int digit = (x >> i) & 1;
            if (!trie->next[digit]) trie->next[digit] = new Trie();
            trie = trie->next[digit];
        }
    }

    int query(int x) {
        Trie *trie = this;
        int res = 0;
        for (int i = 30; ~i; i--) {
            int digit = (x >> i) & 1;
            if (trie->next[digit ^ 1]) {
                trie = trie->next[digit ^ 1];
                res = (res << 1) + digit ^ 1;
            } else if (trie->next[digit]) {
                trie = trie->next[digit];
                res = (res << 1) + digit;
            } else {
                break;
            }
        }
        res ^= x;
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        Trie *trie = new Trie();
        for (int num: nums) trie->insert(num);
        int res = 0;
        for (int num: nums) res = max(res, trie->query(num));
        return res;
    }
};