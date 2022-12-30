#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            int hour = 0;
            for (int p: piles) {
                hour += (p + mid - 1) / mid;
            }
            if (hour <= h) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};