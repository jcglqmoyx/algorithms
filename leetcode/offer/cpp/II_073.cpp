#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(piles, mid, h)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool valid(vector<int> &piles, int speed, int h) {
        int sum = 0;
        for (int p: piles) {
            sum += (p + speed - 1) / speed;
        }
        return sum <= h;
    }
};