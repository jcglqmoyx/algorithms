#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        using LL = long long;
        const int INF = 0x3f3f3f3f;
        vector<int> min_sec(18, INF);
        for (auto &t: tires) {
            int fi = t[0], ri = t[1];
            LL sum = fi, cost = fi;
            min_sec[1] = min(min_sec[1], fi);
            for (int i = 2; sum <= changeTime + fi; i++) {
                cost *= ri;
                sum += cost;
                min_sec[i] = min(min_sec[i], (int) sum);
            }
        }
        vector<int> f(numLaps + 1, INF);
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; i++) {
            for (int j = max(i - 17, 0); j < i; j++) {
                f[i] = min(f[i], f[j] + changeTime + min_sec[i - j]);
            }
        }
        return f[numLaps];
    }
};