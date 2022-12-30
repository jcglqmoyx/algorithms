#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        f.resize(123);
        for (char c = 'a'; c <= 'z'; c++) f[c] = c;
        for (int i = 0; i < s1.length(); i++) connect(s1[i], s2[i]);
        string res;
        for (char c: baseStr) {
            res.push_back(find(c));
        }
        return res;
    }

private:
    vector<char> f;

    char find(char c) {
        return c == f[c] ? c : find(f[c]);
    }

    void connect(char x, char y) {
        char fx = find(x);
        char fy = find(y);
        if (fx == fy) return;
        if (fx > fy) swap(fx, fy);
        f[fy] = fx;
    }
};