#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        unordered_set<int> S;
        for (int i = left; i <= right; i++) S.insert(i);
        for (auto r: ranges) {
            int low = r[0], high = r[1];
            for (int i = low; i <= high; i++) {
                if (S.count(i)) S.erase(i);
            }
        }
        return S.empty();
    }
};