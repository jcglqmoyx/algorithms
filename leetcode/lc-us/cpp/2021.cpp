#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int brightestPosition(vector<vector<int>> &lights) {
        map<int, int> hash;
        for (auto &light: lights) {
            hash[light[0] - light[1]]++;
            hash[light[0] + light[1] + 1]--;
        }
        int sum = 0, max_brightness = 0, res = 0;
        for (auto &[pos, cnt]: hash) {
            sum += cnt;
            if (sum > max_brightness) {
                max_brightness = sum;
                res = pos;
            }
        }
        return res;
    }
};