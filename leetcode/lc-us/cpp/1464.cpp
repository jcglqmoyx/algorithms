#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int first = 1, second = 1;
        for (int num: nums) {
            if (num > second) {
                if (num > first) {
                    second = first;
                    first = num;
                } else {
                    second = num;
                }
            }
        }
        return (first - 1) * (second - 1);
    }
};