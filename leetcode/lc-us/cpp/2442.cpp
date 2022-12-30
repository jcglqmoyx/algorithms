#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int> &nums) {
        unordered_set<int> S;
        for (int x: nums) {
            S.insert(x);
            int y = 0;
            while (x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            S.insert(y);
        }
        return (int) S.size();
    }
};