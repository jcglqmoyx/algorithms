#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = (int) s.size();
        vector<int> diff(n + 1);
        for (auto &shift: shifts) {
            int start = shift[0], end = shift[1];
            int dist = shift[2] ? 1 : -1;
            diff[start] += dist;
            diff[end + 1] -= dist;
        }
        for (int i = 0; i < n - 1; ++i) {
            diff[i + 1] += diff[i];
        }
        for (int i = 0; i < n; ++i) {
            s[i] = (char) ((s[i] - 'a' + diff[i] % 26 + 26) % 26 + 'a');
        }
        return s;
    }
};