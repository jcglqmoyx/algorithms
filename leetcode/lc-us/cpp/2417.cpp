#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int n) {
        int res = 1;
        for (int i = 0; i < n / 2; i++) {
            res = res * 10;
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            res = res * 10 + 1;
        }
        return res;
    }

public:
    int closestFair(int n) {
        if (n <= 10) return 10;
        int m = n;
        vector<int> v;
        while (n) v.push_back(n % 10), n /= 10;
        if (v.size() & 1) {
            return get((int) v.size() + 1);
        }
        auto mx = (long long) pow(10, v.size());
        for (int num = m;; num++) {
            if (num == mx) break;
            int cnt = 0;
            int t = num;
            while (t) {
                int x = t % 10;
                if (x & 1) cnt++;
                else cnt--;
                t /= 10;
            }
            if (!cnt) return num;
        }
        return get((int) v.size() + 3);
    }
};