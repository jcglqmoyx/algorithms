#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>> &regions, string region1, string region2) {
        unordered_map<string, string> p;
        for (auto &r: regions) {
            for (int i = 1; i < r.size(); i++) {
                p[r[i]] = r[0];
            }
        }
        string tmp = region1;
        unordered_set<string> hash;
        while (p.count(region1)) {
            hash.insert(p[region1]);
            region1 = p[region1];
        }
        while (!hash.count(region2) && region2 != tmp) {
            region2 = p[region2];
        }
        return region2;
    }
};