#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
        int m = (int) languages.size();
        vector<vector<bool>> skills(m + 1, vector<bool>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int l: languages[i]) {
                skills[i + 1][l] = true;
            }
        }
        unordered_set<int> people;
        for (auto &f: friendships) {
            bool flag = true;
            for (int l = 1; l <= n; l++) {
                if (skills[f[0]][l] && skills[f[1]][l]) {
                    flag = false;
                    break;
                }
            }
            if (flag) people.insert(f[0]), people.insert(f[1]);
        }
        vector<int> cnt(n + 1);
        for (auto p: people) {
            for (int skill = 1; skill <= n; skill++) {
                if (skills[p][skill]) cnt[skill]++;
            }
        }
        int mx = 0;
        for (int num: cnt) mx = max(mx, num);
        return (int) people.size() - mx;
    }
};