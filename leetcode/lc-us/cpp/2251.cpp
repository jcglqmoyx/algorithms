#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        vector<int> v;
        for (auto &f: flowers) {
            int x = f[0], y = f[1];
            v.push_back(x), v.push_back(y);
        }
        for (auto p: persons) {
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        auto get = [&](int x) {
            return (int) (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
        };

        int n = (int) v.size();
        vector<int> s(n + 2);
        for (auto &f: flowers) {
            int x = get(f[0]), y = get(f[1]);
            s[x]++, s[y + 1]--;
        }
        for (int i = 1; i <= n; i++) s[i] += s[i - 1];
        vector<int> res;
        res.reserve(persons.size());
        for (int p: persons) {
            res.push_back(s[get(p)]);
        }
        return res;
    }
};