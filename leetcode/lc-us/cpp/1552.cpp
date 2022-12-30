#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = 1e9;
        while (l < r) {
            int dist = l + (r - l + 1) / 2;
            int cnt = 1, last = position[0];
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - last >= dist) {
                    cnt++;
                    last = position[i];
                }
            }
            if (cnt >= m) l = dist;
            else r = dist - 1;
        }
        return l;
    }
};