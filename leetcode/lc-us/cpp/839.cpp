#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string> &strs) {
        int n = (int) strs.size();
        f.reserve(n);
        rank.resize(n, 1);
        size = n;
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) {
                    add(i, j);
                }
            }
        }
        return size;
    }

private:
    vector<int> f;
    vector<int> rank;
    int size = 0;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void add(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        rank[fy] += rank[fx];
        size--;
    }

    bool similar(string &a, string &b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) count++;
            if (count > 2) return false;
        }
        return true;
    }
};