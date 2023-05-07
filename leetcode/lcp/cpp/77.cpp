#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int runeReserve(vector<int> &runes) {
        int n = runes.size();
        sort(runes.begin(), runes.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && runes[j] - runes[j - 1] <= 1) j++;
            res = max(res, j - i);
            i = j - 1;
        }
        return res;
    }
};