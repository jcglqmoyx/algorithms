#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int two = 0, five = 0;
        for (int i = left; i <= right; i++) {
            int t = i;
            while (t % 2 == 0) t /= 2, two++;
            while (t % 5 == 0) t /= 5, five++;
        }
        int D = min(two, five);
        two = five = D;

        long long low = 1, low2 = 1;
        bool flag = false;
        for (int i = left; i <= right; i++) {
            int t = i;
            while (two > 0 && t % 2 == 0) t /= 2, two--;
            while (five > 0 && t % 5 == 0) t /= 5, five--;
            low = low * t % 100000;
            if (!flag) {
                low2 = low2 * t;
                if (low2 >= 10000000000LL) flag = true;
            }
        }

        if (!flag) return to_string(low2) + "e" + to_string(D);

        long double b = 0;
        for (int i = left; i <= right; i++) b += log((long double) i) / log((long double) 10.0);
        long long high = pow((long double) 10.0, b - (long long) b + 4);
        char buffer[20] = {0};
        snprintf(buffer, 20, "%05lld", low);
        return to_string(high) + "..." + string(buffer) + "e" + to_string(D);
    }
};