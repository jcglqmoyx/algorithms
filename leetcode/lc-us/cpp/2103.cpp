#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int n = (int) rings.size();
        int cnt[10][3] = {0};
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int idx = rings[i + 1] - '0';
            if (color == 'R') cnt[idx][0]++;
            else if (color == 'G') cnt[idx][1]++;
            else if (color == 'B') cnt[idx][2]++;
        }
        int res = 0;
        for (auto &i: cnt) {
            if (i[0] && i[1] && i[2]) res++;
        }
        return res;
    }
};