#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
        int n = (int) favoriteCompanies.size();
        vector<int> res;
        vector<unordered_set<string>> s;
        for (auto &f: favoriteCompanies) {
            unordered_set<string> companies;
            for (auto &c: f) companies.insert(c);
            s.push_back(companies);
        }
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (favoriteCompanies[i].size() > favoriteCompanies[j].size()) continue;
                bool tmp = true;
                for (auto &c: favoriteCompanies[i]) {
                    if (!s[j].count(c)) {
                        tmp = false;
                        break;
                    }
                }
                if (tmp) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};