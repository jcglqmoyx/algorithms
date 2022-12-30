#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int n = (int) nums.size(), vis[50000], pos[50000];
        int Max = 0, Min = INT_MAX;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            vis[nums[i]]++;
            if (vis[nums[i]] > Max) {
                Max = vis[nums[i]];
            }
            pos[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (vis[nums[i]] == Max && vis[nums[i]]) {
                Min = Min > pos[nums[i]] - i + 1 ? pos[nums[i]] - i + 1 : Min;
                vis[nums[i]] = 0;
            }
        }
        return Min;
    }
};