class Solution {
    using LL = long long;

    LL get(LL x) {
        LL cnt = 0;
        while (x) {
            cnt += x / 5;
            x /= 5;
        }
        return cnt;
    }

public:
    int preimageSizeFZF(int k) {
        LL l = 0, r = 5e9;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            if (get(mid) < k) l = mid + 1;
            else r = mid;
        }

        LL left = l;
        l = 0, r = 5e9;
        while (l < r) {
            LL mid = l + (r - l + 1) / 2;
            if (get(mid) <= k) l = mid;
            else r = mid - 1;
        }
        return (int) (l - left + 1);
    }
};