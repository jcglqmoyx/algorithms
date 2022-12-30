#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int n = (int) candies.size();
        vector<bool> res(n);
        int m = 0;
        for (int candy: candies) {
            m = max(m, candy);
        }
        for (int i = 0; i < n; i++) {
            res[i] = candies[i] + extraCandies >= m;
        }
        return res;
    }
};