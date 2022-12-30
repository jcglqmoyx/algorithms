#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int len) {
        sort(tiles.begin(), tiles.end());
        int n = (int) tiles.size(), res = 0, cover = 0;
        for (int i = 0, j = 0; i < n; i++) {
            int start = tiles[i][0], end = start + len - 1;
            while (j < n && tiles[j][1] <= end) {
                cover += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            if (j < n && tiles[j][0] <= end) res = max(res, cover + end - tiles[j][0] + 1);
            else res = max(res, cover);
            if (j == n) break;
            cover -= tiles[i][1] - tiles[i][0] + 1;
        }
        return res;
    }
};