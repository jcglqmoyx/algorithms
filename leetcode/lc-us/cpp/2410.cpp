#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        sort(players.begin(), players.end()), sort(trainers.begin(), trainers.end());
        int n = (int) players.size(), m = (int) trainers.size();
        int res = 0;
        for (int i = 0, j = 0; i < n && j < m; i++) {
            while (j < m && trainers[j] < players[i]) j++;
            if (j < m) res++, j++;
        }
        return res;
    }
};