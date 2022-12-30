#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string> &votes) {
        int n = (int) votes[0].size();
        vector<vector<int>> v(26, vector<int>(n));
        for (auto &vote: votes) {
            for (int i = 0; i < n; i++) {
                v[vote[i] - 'A'][i]++;
            }
        }
        sort(votes[0].begin(), votes[0].end(), [&](char a, char b) {
            for (int i = 0; i < n; i++) {
                if (v[a - 'A'][i] != v[b - 'A'][i]) return v[a - 'A'][i] > v[b - 'A'][i];
            }
            return a < b;
        });
        return votes[0];
    }
};