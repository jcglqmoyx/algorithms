#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0, res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            cost += (abs(t[j] - s[j]));
            while (i <= j && cost > maxCost) {
                cost -= abs(t[i] - s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
