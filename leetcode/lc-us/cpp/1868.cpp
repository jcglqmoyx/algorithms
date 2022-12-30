#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>> &encoded1, vector<vector<int>> &encoded2) {
        vector<vector<int>> res;
        for (int i = 0, a = 0, j = 0, b = 0; i < encoded1.size();) {
            if (a < encoded1[i][1] && b < encoded2[j][1]) {
                int product = encoded1[i][0] * encoded2[j][0];
                int cnt = min(encoded1[i][1] - a, encoded2[j][1] - b);
                a += cnt;
                b += cnt;
                if (res.empty() || res.back()[0] != product) {
                    res.push_back({product, cnt});
                } else if (res.back()[0] == product) {
                    res.back()[1] += cnt;
                }
            } else if (a == encoded1[i][1]) {
                i++;
                a = 0;
            } else if (b == encoded2[j][1]) {
                j++;
                b = 0;
            }
        }
        return res;
    }
};