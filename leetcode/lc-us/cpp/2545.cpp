#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
        using VI = vector<int>;

        sort(score.begin(), score.end(), [&](const VI &a, const VI &b) {
            return a[k] > b[k];
        });
        return score;
    }
};