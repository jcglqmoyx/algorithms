#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
        int n = (int) reward1.size();
        int res = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {reward1[i], reward2[i]};
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second - a.first < b.second - b.first;
        });
        for (int i = 0; i < k; i++) {
            res += v[i].first;
        }
        for (int i = k; i < n; i++) {
            res += v[i].second;
        }
        return res;
    }
};