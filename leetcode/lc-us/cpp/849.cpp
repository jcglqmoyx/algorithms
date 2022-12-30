#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int res, len = 0, n = (int) seats.size();
        int l = 0, r = n - 1;
        while (l <= r && seats[l] == 0) l++;
        while (r >= l && seats[r] == 0) r--;
        res = max(1, max(l, n - r - 1));
        for (int i = l + 1; i <= r; i++) {
            if (seats[i] == 0) len++;
            else {
                res = max(res, (len + 1) / 2);
                len = 0;
            }
        }
        return res;
    }
};