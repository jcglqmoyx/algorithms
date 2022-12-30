#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isThree(int n) {
        if (n == 1) return false;
        int cnt = 0;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) cnt += 2;
        }
        int square_root = (int) sqrt(n);
        if (square_root * square_root == n) cnt++;
        else cnt += 2;
        return cnt == 3;
    }
};