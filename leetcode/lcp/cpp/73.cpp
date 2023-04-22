#include <bits/stdc++.h>

using namespace std;

class Solution {
    set<string> hash;

    int process(string &s) {
        int newly_found = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (i + 1 == s.size() || s[i] == '-') {
                int len = i - j;
                if (i + 1 == s.size()) len++;
                string place = s.substr(j, len);
                if (!hash.count(place)) newly_found++, hash.insert(place);
                i++, j = i + 1;
            }
        }
        return newly_found;
    }

public:
    int adventureCamp(vector<string> &expeditions) {
        process(expeditions[0]);
        int mx = 0, idx = -1;
        for (int i = 0; i < expeditions.size(); i++) {
            int t = process(expeditions[i]);
            if (t > mx) mx = t, idx = i;
        }
        return idx;
    }
};