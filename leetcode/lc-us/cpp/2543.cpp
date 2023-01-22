class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int v = __gcd(targetX, targetY);
        return v == (v & -v);
    }
};