#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        int n = (int) nums.size();
        if (n % k) return false;
        unordered_map<int, int> cnt;
        for (int num: nums) cnt[num]++;
        sort(nums.begin(), nums.end());
        for (int num: nums) {
            if (cnt.find(num) == cnt.end()) continue;
            for (int i = num; i < num + k; i++) {
                if (cnt.find(i) == cnt.end()) return false;
                cnt[i]--;
                if (cnt[i] == 0) cnt.erase(i);
            }
        }
        return true;
    }
};