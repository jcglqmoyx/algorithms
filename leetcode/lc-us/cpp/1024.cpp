#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        sort(clips.begin(), clips.end());
        int cnt = 0, end = 0, n = (int) clips.size();
        for (int i = 0; i < n && end < time; i++) {
            if (clips[i][0] > end) {
                return -1;
            }
            int j = i;
            int idx = i;
            int mx = clips[i][1];
            while (j < n && clips[j][0] <= end) {
                if (clips[j][1] > mx) {
                    mx = clips[j][1];
                    idx = j;
                }
                j++;
            }
            i = idx;
            end = clips[idx][1];
            cnt++;
        }
        if (end < time) return -1;
        return cnt;
    }
};