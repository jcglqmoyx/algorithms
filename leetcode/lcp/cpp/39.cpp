#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>> &source, vector<vector<int>> &target) {
        int res = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < source.size(); i++) {
            for (int j = 0; j < source[0].size(); j++) {
                map[source[i][j]]++;
            }
        }
        for (auto &r: target) {
            for (int x: r) {
                if (map.count(x)) {
                    map[x]--;
                    if (map[x] == 0) map.erase(x);
                } else res++;
            }
        }
        return res;
    }
};