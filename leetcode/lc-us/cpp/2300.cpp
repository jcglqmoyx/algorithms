#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = (int) spells.size(), m = (int) potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            long x = ((success + spells[i] - 1) / spells[i]);
            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (potions[mid] >= x) r = mid;
                else l = mid + 1;
            }
            res[i] = m - l;
        }
        return res;
    }
};