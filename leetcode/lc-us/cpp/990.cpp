#include <bits/stdc++.h>

using namespace std;

class Solution {
    int p[26], rank[26];

    int find(int x) {
        return x == p[x] ? x : find(p[x]);
    }

    bool connect(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        if (rank[fa] < rank[fb]) {
            swap(fa, fb);
        }
        p[fb] = fa;
        rank[fa]++;
        return true;
    }

public:
    bool equationsPossible(vector<string> &equations) {
        for (int i = 0; i < 26; i++) {
            p[i] = i;
            rank[i] = 1;
        }
        for (string &e: equations) {
            if (e[1] == '=') {
                connect(e[0] - 'a', e[3] - 'a');
            }
        }
        for (string &e: equations) {
            if (e[1] == '!') {
                if (find(e[0] - 'a') == find(e[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};