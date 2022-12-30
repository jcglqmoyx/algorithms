#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums, int start, int goal) {
        bool st[1001] = {};
        int step = 0;
        queue<int> q;
        q.push(start);
        st[start] = true;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                int t = q.front();
                q.pop();
                if (t < 0 || t > 1000) continue;
                for (int num: nums) {
                    int a = t + num, b = t - num, c = t ^ num;
                    if (a == goal || b == goal || c == goal) return step;
                    if (a >= 0 && a <= 1000 && !st[a]) q.push(a), st[a] = true;
                    if (b >= 0 && b <= 1000 && !st[b]) q.push(b), st[b] = true;
                    if (c >= 0 && c <= 1000 && !st[c]) q.push(c), st[c] = true;
                }
            }
        }
        return -1;
    }
};