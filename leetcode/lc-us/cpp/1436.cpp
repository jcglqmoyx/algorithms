#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_map<string, int> cities;
        for (vector<string> path: paths) {
            cities[path[0]]++;
            cities[path[1]] += 2;
        }
        for (const auto &city: cities) {
            if (city.second == 2) {
                return city.first;
            }
        }
        return "";
    }
};