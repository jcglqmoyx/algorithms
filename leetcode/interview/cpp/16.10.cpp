#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int> &birth, vector<int> &death) {
        int map[102] = {};
        for (int i = 0; i < birth.size(); i++) {
            map[birth[i] - 1900]++;
            map[death[i] - 1900 + 1]--;
        }
        int maximum = 0;
        int index = 0;
        int sum = 0;
        for (int i = 0; i < 101; i++) {
            sum += map[i];
            if (sum > maximum) {
                maximum = sum;
                index = i;
            }
        }
        return index + 1900;
    }
};