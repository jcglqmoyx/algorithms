#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int map[26] = {};
        iota(map, map + 26, -1);
        for (int i = 0; i < S.length(); i++) {
            map[S[i] - 'a'] = i;
        }
        vector<int> partitions;
        int low = 0, high = 0;
        while (low < S.length()) {
            for (int i = low; i < map[S[high] - 'a']; i++) {
                if (map[S[i] - 'a'] > high) {
                    high = map[S[i] - 'a'];
                }
            }
            partitions.push_back(high - low + 1);
            low = high + 1;
            high = low;
        }
        return partitions;
    }
};