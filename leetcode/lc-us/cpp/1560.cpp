#include <bits/stdc++.h>

using namespace std;

class Solution {
    int map[101];

    void visit(int start, int end, int n) {
        if (start < end) {
            for (int i = start + 1; i <= end; i++) {
                map[i]++;
            }
        } else {
            for (int i = start + 1; i <= n; i++) {
                map[i]++;
            }
            for (int i = 1; i <= end; i++) {
                map[i]++;
            }
        }
    }

public:
    vector<int> mostVisited(int n, vector<int> &rounds) {
        memset(map, 0, sizeof map);
        map[rounds[0]]++;
        vector<int> res;
        for (int i = 0; i < rounds.size() - 1; i++) {
            visit(rounds[i], rounds[i + 1], n);
        }
        int max_freq = 0;
        for (int freq: map) {
            max_freq = max(max_freq, freq);
        }
        for (int i = 1; i <= 100; i++) {
            if (map[i] == max_freq) {
                res.push_back(i);
            }
        }
        return res;
    }
};