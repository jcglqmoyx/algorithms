#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        n = (int) s.size();
        rk.resize(n, 1), parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &p: pairs) add(p[0], p[1]);
        unordered_map<int, vector<pair<char, int>>> hash;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            hash[root].push_back({s[i], i});
        }
        for (auto &[k, v]: hash) {
            vector<char> chars;
            vector<int> indices;
            for (auto &t: v) {
                chars.push_back(t.first);
                indices.push_back(t.second);
            }
            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); i++) {
                s[indices[i]] = chars[i];
            }
        }
        return s;
    }

private :
    int n;
    vector<int> parent, rk;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        parent[px] = py;
        rk[py] += rk[px];
    }
};