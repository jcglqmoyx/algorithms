class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n * 2 - 2);
        if (time < n) return time + 1;
        else return n * 2 - time - 1;
    }
};