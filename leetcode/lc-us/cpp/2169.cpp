class Solution {
public:
    int countOperations(int a, int b) {
        int res = 0;
        while (a && b) {
            res++;
            if (a >= b) a -= b;
            else b -= a;
        }
        return res;
    }
};