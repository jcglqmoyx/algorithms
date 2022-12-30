#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        for (auto &s: stones) {
            add(s[0] + 10001, s[1]);
        }
        return (int) stones.size() - count;
    }

private:
    int count = 0;
    unordered_map<int, int> p, rk;

    inline int find(int x) {
        if (p.find(x) == p.end()) {
            p[x] = x;
            count++;
            return x;
        }
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    inline void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (px > py) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
        count--;
    }
};