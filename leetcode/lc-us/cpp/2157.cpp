#include <bits/stdc++.h>

using namespace std;

class Solution {
    int mx, size;
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
        mx = max(mx, rk[py]);
        size--;
    }

public:
    vector<int> groupStrings(vector<string> &words) {
        mx = 0, size = (int) words.size();
        p.resize(size), rk.resize(size, 1);
        for (int i = 0; i < size; i++) p[i] = i, rk[i] = 1;
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_map<int, int> hash;
        int n = (int) words.size();
        for (int i = 0; i < n; i++) {
            string &s = words[i];
            int val = 0;
            for (char c: s) val |= 1 << (c - 'a');
            if (hash.count(val)) {
                connect(hash[val], i);
                continue;
            }
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (val >> j & 1) {
                        int t = val;
                        t ^= 1 << j;
                        t |= 1 << k;
                        if (hash.count(t)) {
                            connect(hash[t], i);
                        }
                    }
                }
            }
            hash[val] = i;
        }
        return {size, max(mx, 1)};
    }
};