#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        int map[46] = {0};
        for (int n = lowLimit; n <= highLimit; n++) {
            map[calc(n)]++;
        }
        for (int count: map) res = max(res, count);
        return res;
    }

private:
    static int calc(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};