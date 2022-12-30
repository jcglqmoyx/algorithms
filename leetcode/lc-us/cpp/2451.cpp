#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string oddString(vector<string> &words) {
        int n = (int) words.size(), m = (int) words[0].size();
        for (int i = 1; i < m; i++) {
            unordered_map<int, int> cnt;
            for (int j = 0; j < 3; j++) {
                cnt[words[j][i] - words[j][i - 1]]++;
            }
            int diff;
            for (auto[k, v]: cnt) {
                if (v >= 2) {
                    diff = k;
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                if (words[j][i] - words[j][i - 1] != diff) {
                    return words[j];
                }
            }
        }
        return "";
    }
};