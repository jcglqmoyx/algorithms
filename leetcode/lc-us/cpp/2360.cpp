#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int n = (int) edges.size();
        vector<int> time(n);
        int res = -1;
        for (int i = 0, clock = 1; i < edges.size(); i++) {
            if (time[i]) continue;
            for (int x = i, start = clock; ~x; x = edges[x]) {
                if (time[x]) {
                    if (time[x] >= start) {
                        res = max(res, clock - time[x]);
                    }
                    break;
                }
                time[x] = clock++;
            }
        }
        return res;
    }
};