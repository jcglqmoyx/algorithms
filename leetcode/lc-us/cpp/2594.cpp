#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        using LL = long long;
        LL l = 0, r = 1e14;
        while (l < r) {
            LL mid = (l + r) >> 1, cnt = 0;
            for (int rank: ranks) cnt += (int) sqrt(mid / rank);
            if (cnt >= cars) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};