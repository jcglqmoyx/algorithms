#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        int map[101] = {};
        for (int n: nums) {
            map[n]++;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++) {
            if (map[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};