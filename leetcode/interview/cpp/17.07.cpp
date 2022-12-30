#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> parent;
    unordered_map<int, int> cnt;
    unordered_map<string, int> map1;
    unordered_map<int, string> map2;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (map2[py] > map2[px]) swap(px, py);
        parent[px] = py;
        cnt[py] += cnt[px];
    }

public:
    vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms) {
        int n = (int) names.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            string &e = names[i];
            int idx = (int) e.find('(');
            string name = e.substr(0, idx);
            map1[name] = i;
            map2[i] = name;
            cnt[i] = stoi(e.substr(idx + 1, (int) e.length() - 2));
        }
        for (auto &s: synonyms) {
            int idx = (int) s.find(',');
            string name1 = s.substr(1, idx - 1);
            string name2 = s.substr(idx + 1, (int) s.size() - idx - 2);
            connect(map1[name1], map1[name2]);
        }
        vector<string> res;
        unordered_set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(find(i));
        }
        for (int r: roots) {
            string &name = map2[r];
            int amount = cnt[r];
            res.push_back(name + '(' + to_string(amount) + ')');
        }
        return res;
    }
};