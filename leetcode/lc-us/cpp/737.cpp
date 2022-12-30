#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    using VS = vector<string>;
    using VVS = vector<vector<string>>;

    unordered_map<string, string> p;
    unordered_map<string, int> rk;

    string find(const string &s) {
        if (!p.count(s)) {
            p[s] = s;
            rk[s] = 1;
        } else if (p[s] != s) {
            p[s] = find(p[s]);
        }
        return p[s];
    }

    void add(string &x, string &y) {
        string px = find(x), py = find(y);
        if (px == py) return;
        int rk1 = rk[px], rk2 = rk[py];
        if (rk1 > rk2) swap(px, py);
        p[px] = py;
        rk[py] = rk1 + rk2;
    }

public:
    bool areSentencesSimilarTwo(VS &sentence1, VS &sentence2, VVS &similarPairs) {
        int n = (int) sentence1.size();
        if (sentence2.size() != n) return false;
        for (auto &pair: similarPairs) add(pair[0], pair[1]);
        for (int i = 0; i < n; i++) {
            string px = find(sentence1[i]), py = find(sentence2[i]);
            if (px != py) return false;
        }
        return true;
    }
};