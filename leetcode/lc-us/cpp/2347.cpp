#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        int suits_map[4] = {}, rank_map[13] = {};
        for (char c: suits) {
            suits_map[c - 'a']++;
            if (suits_map[c - 'a'] >= 5) {
                return "Flush";
            }
        }
        for (int rank: ranks) {
            rank_map[rank - 1]++;
        }
        for (int i: rank_map) {
            if (i >= 3) {
                return "Three of a Kind";
            }
        }
        for (int i: rank_map) {
            if (i >= 2) {
                return "Pair";
            }
        }
        return "High Card";
    }
};