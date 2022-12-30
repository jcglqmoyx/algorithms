class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while (numBottles >= numExchange) {
            int exchange = numBottles / numExchange;
            numBottles = exchange + numBottles % numExchange;
            sum += exchange;
        }
        return sum;
    }
};