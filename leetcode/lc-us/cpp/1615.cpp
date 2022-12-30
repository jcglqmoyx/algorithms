#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        int maximal_network_rank = 0;
        unordered_map<int, unordered_set<int>> map;
        for (vector<int> &road: roads) {
            map[road[0]].insert(road[1]);
            map[road[1]].insert(road[0]);
        }
        for (const auto &city_a: map) {
            for (const auto &city_b: map) {
                if (city_a.first != city_b.first) {
                    if (map[city_a.first].count(city_b.first)) {
                        maximal_network_rank = max(maximal_network_rank,
                                                   (int) map[city_a.first].size() + (int) map[city_b.first].size() - 1);
                    } else {
                        maximal_network_rank = max(maximal_network_rank, (int) map[city_a.first].size() +
                                                                         (int) map[city_b.first].size());
                    }
                }
            }
        }
        return maximal_network_rank;
    }
};