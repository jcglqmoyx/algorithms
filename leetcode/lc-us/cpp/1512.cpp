#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        int res = 0;
        int count[101] = {};
        for (int num: nums) {
            count[num]++;
        }
        for (int n: count) {
            if (n > 1) {
                res += n * (n - 1) / 2;
            }
        }
        return res;
    }
};