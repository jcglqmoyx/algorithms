#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(vector<int> &uf, int i) {
        if (uf[i] == i) return i;
        return get(uf, get(uf, uf[i]));
    }

    void connect(vector<int> &uf, int i, int j) {
        int x = get(uf, i);
        int y = get(uf, j);
        if (x == y) return;
        uf[x] = y;
    }

public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        vector<int> uf(source.size());
        for (int i = 0; i < uf.size(); i++) {
            uf[i] = i;
        }
        for (vector<int> &s: allowedSwaps) connect(uf, s[0], s[1]);
        unordered_map<int, unordered_multiset<int>> s, t;
        for (int i = 0; i < source.size(); i++) {
            int f = get(uf, i);
            s[f].insert(source[i]);
            t[f].insert(target[i]);
        }
        int count = 0;
        for (int i = 0; i < source.size(); i++) {
            if (s.find(i) != s.end()) {
                for (int x: s[i]) {
                    if (t[i].find(x) == t[i].end()) count++;
                    else {
                        t[i].erase(t[i].find(x));
                    }
                }
            }
        }
        return count;
    }
};