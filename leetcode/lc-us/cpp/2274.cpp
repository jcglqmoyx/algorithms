#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        int res = 0;
        for (int i = 0; i + 1 < special.size(); i++) {
            res = max(res, special[i + 1] - special[i] - 1);
        }
        return res;
    }
};