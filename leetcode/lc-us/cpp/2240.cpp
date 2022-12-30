class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        using LL = long long;
        LL res = 0;
        for (int x = 0;; x++) {
            int left = total - cost1 * x;
            if (left < 0) break;
            res += left / cost2 + 1;
        }
        return res;
    }
};