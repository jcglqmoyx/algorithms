#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
        map<string, vector<int>> hash;
        int n = (int) keyName.size();
        for (int i = 0; i < n; i++) {
            int h = stoi(keyTime[i].substr(0, 2)), m = stoi(keyTime[i].substr(3));
            hash[keyName[i]].push_back(h * 60 + m);
        }
        vector<string> res;
        for (auto &[k, v]: hash) {
            sort(v.begin(), v.end());
            int size = (int) v.size();
            for (int i = 0; i < size - 2; i++) {
                if (v[i + 2] - v[i] <= 60) {
                    res.push_back(k);
                    break;
                }
            }
        }
        return res;
    }
};