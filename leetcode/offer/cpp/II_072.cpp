class Solution {
public:
    int mySqrt(int x) {
        using LL = long long;
        LL l = 0, r = x;
        while (l < r) {
            LL mid = l + (r - l + 1) / 2;
            if (mid * mid > x) r = mid - 1;
            else l = mid;
        }
        return (int) l;
    }
};