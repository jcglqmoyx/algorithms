#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = (int) blocks.size();
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }
        }
        int res = cnt;
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }
            if (blocks[i - k] == 'W') {
                cnt--;
            }
            res = min(res, cnt);
        }
        return res;
    }
};