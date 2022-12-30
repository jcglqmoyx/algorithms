#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        int n = (int) adjacentPairs.size();
        vector<int> arr;
        arr.reserve(n + 1);
        unordered_map<int, int> cnt;
        unordered_map<int, vector<int>> g;
        unordered_set<int> visited;
        for (auto &pair: adjacentPairs) {
            cnt[pair[0]]++, cnt[pair[1]]++;
            g[pair[0]].push_back(pair[1]), g[pair[1]].push_back(pair[0]);
        }
        int start;
        for (auto[k, v]: cnt) {
            if (v == 1) {
                start = k;
                break;
            }
        }
        arr.push_back(start);
        visited.insert(start);
        while (visited.size() <= n) {
            auto next = g[start];
            for (int j: next) {
                if (!visited.count(j)) {
                    arr.push_back(j);
                    visited.insert(j);
                    start = j;
                }
            }
        }
        return arr;
    }
};