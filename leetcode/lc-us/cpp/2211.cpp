#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int l = 0, r = (int) directions.size() - 1;
        while (l <= r && directions[l] == 'L') l++;
        while (r >= l && directions[r] == 'R') r--;
        if (l >= r) return 0;
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] == 'S') cnt++;
        }
        return r - l + 1 - cnt;
    }
};