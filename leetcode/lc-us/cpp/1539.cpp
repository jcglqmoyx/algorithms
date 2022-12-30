#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int map[1001] = {};
        for (int num: arr) {
            map[num]++;
        }
        int count = 0, num = 0;
        while (count < k) {
            num++;
            if (num > 1000 || !map[num]) {
                count++;
            }
        }
        return num;
    }
};