#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTime(vector<int> &time, int m) {
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(time, m, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    static bool check(vector<int> &time, int days, int mid) {
        int n = (int) time.size();
        int i = 0, cnt = 0;
        while (i < n) {
            cnt++;
            int mx = time[i], sum = time[i];
            int j = i + 1;
            while (j < n) {
                mx = max(mx, time[j]);
                if (sum + time[j] <= mid + mx) sum += time[j++];
                else break;
            }
            i = j - 1;
            i++;
        }
        return cnt <= days;
    }
};