#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        vector<int> res;
        map<int, vector<int>, greater<>> M;
        for (auto &r: rectangles) {
            int x = r[0], y = r[1];
            M[y].push_back(x);
        }
        for (auto &[k, v]: M) {
            sort(v.begin(), v.end());
        }
        for (auto p: points) {
            int x = p[0], y = p[1];
            int cnt = 0;
            for (auto &it: M) {
                int height = it.first;
                if (y > height) break;
                int len = (int) it.second.size();
                cnt += len - (int) (lower_bound(it.second.begin(), it.second.end(), x) - it.second.begin());
            }
            res.push_back(cnt);
        }
        return res;
    }
};