#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(int radius, vector<int> &houses, vector<int> &heaters) {
        int n = (int) heaters.size();
        for (int i = 0, j = 0; i < houses.size(); i++) {
            while (j < n && abs(houses[i] - heaters[j]) > radius) j++;
            if (j == n) return false;
        }
        return true;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};