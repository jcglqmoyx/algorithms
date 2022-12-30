#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> cnt, end;
        for (int num: nums) cnt[num]++;
        for (int x: nums) {
            if (cnt.find(x) == cnt.end()) continue;
            int y = x + 1, z = x + 2;
            if (end.find(x - 1) != end.end()) {
                end[x - 1]--;
                if (end[x - 1] == 0) end.erase(x - 1);
                end[x]++;
                cnt[x]--;
                if (cnt[x] == 0) cnt.erase(x);
            } else {
                if (cnt.find(y) == cnt.end() || cnt.find(z) == cnt.end()) return false;
                cnt[x]--, cnt[y]--, cnt[z]--;
                if (cnt[x] == 0) cnt.erase(x);
                if (cnt[y] == 0) cnt.erase(y);
                if (cnt[z] == 0) cnt.erase(z);
                end[z]++;
            }
        }
        return true;
    }
};