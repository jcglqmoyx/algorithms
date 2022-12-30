#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int x: nums) {
            if (x & 1) continue;
            ++cnt[x];
        }
        int ans = -1;
        for (auto &[x, c]: cnt) {
            if (ans == -1 || c > cnt[ans]) ans = x;
            else if (c == cnt[ans]) ans = min(ans, x);
        }
        return ans;
    }
};
