class Solution {
public:
    int gcd(int x, int y) {
        return x % y == 0 ? y : gcd(y, x % y);
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity > jug1Capacity + jug2Capacity) return false;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};