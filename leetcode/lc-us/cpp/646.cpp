#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int cnt = 1, end = pairs[0][1];
        for (auto &p: pairs) {
            if (p[0] > end) {
                end = p[1];
                cnt++;
            }
        }
        return cnt;
    }
};