#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int l = *min_element(bloomDay.begin(), bloomDay.end()), r = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        int mx = r;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(bloomDay, m, k, mid)) r = mid;
            else l = mid + 1;
        }
        return l == mx ? -1 : l;
    }

private:
    static bool check(vector<int> &bloom_day, int m, int k, int day) {
        int n = (int) bloom_day.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (bloom_day[i] <= day) {
                int j = i + 1;
                while (j < n && bloom_day[j] <= day) j++;
                cnt += (j - i) / k;
                i = j - 1;
            }
        }
        return cnt >= m;
    }
};