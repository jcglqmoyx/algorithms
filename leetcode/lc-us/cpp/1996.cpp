#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) return a[0] > b[0];
            else return a[1] < b[1];
        });
        int cnt = 0;
        int max_defense = 0;
        for (auto &p: properties) {
            if (p[1] < max_defense) cnt++;
            else max_defense = p[1];
        }
        return cnt;
    }
};