#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 2.5e7;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(weights, days, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    inline bool check(vector<int> &w, int days, int capacity) {
        int time = 1, n = (int) w.size();
        int load = capacity;
        int i = 0;
        while (i < n) {
            while (i < n && load >= w[i]) load -= w[i++];
            if (i < n) load = capacity, time++;
        }
        return time <= days;
    }
};