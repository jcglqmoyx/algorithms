#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        vector<string> res;
        unordered_map<string, int> map;
        for (string &cpdomain: cpdomains) {
            int space = (int) cpdomain.find(' ');
            int num = stoi(cpdomain.substr(0, space));
            map[cpdomain.substr(space + 1, cpdomain.length() - space - 1)] += num;
            for (int i = space + 2; i < cpdomain.length() - 1; i++) {
                if (cpdomain[i] == '.') {
                    map[cpdomain.substr(i + 1, cpdomain.length() - i - 1)] += num;
                }
            }
        }
        res.reserve(map.size());
        for (const auto &e: map) {
            res.push_back(to_string(e.second) + " " + e.first);
        }
        return res;
    }
};