#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minimizeError(vector<string> &prices, int target) {
        int mn = 0, mx = 0;
        vector<int> nums;

        for (auto &p: prices) {
            int x = stoi(p.substr(0, p.size() - 3)) * 1000, y = stoi(p.substr(p.size() - 3));
            nums.push_back(x + y);
            mn += x;
            if (y % 1000) mx += x + 1000;
            else mx += x;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int dt1 = a % 1000, dt2;
            if (b % 1000) dt2 = b % 1000;
            else dt2 = 0;
            return dt1 > dt2;
        });
        if (target < mn / 1000 || target > mx / 1000) return "-1";
        int cnt = target - mn / 1000;
        int res = 0;
        for (int i = 0; i < cnt; i++) {
            if (nums[i] % 1000) res += 1000 - nums[i] % 1000;
        }
        for (int i = cnt; i < nums.size(); i++) {
            res += nums[i] % 1000;
        }
        string s = to_string((double) res / 1000);
        return s.substr(0, s.size() - 3);
    }
};