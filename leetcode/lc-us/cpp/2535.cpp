#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int> &nums) {
        int a = 0, b = 0;
        for (int x: nums) a += x;
        for (int x: nums) {
            while (x) {
                b += x % 10;
                x /= 10;
            }
        }
        return abs(a - b);
    }
};