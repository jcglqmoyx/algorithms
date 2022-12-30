#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int a = -1000;
        int b = -1000;
        int c = -1000;
        int m = 1000;
        int n = 1000;
        for (int num: nums) {
            if (num > c) {
                if (num > b) {
                    if (num > a) {
                        c = b;
                        b = a;
                        a = num;
                    } else {
                        c = b;
                        b = num;
                    }
                } else {
                    c = num;
                }
            }
            if (num < n) {
                if (num < m) {
                    n = m;
                    m = num;
                } else {
                    n = num;
                }
            }
        }
        return max(a * b * c, m * n * a);
    }
};