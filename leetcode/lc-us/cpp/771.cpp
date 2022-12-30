#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        int map[128] = {};
        for (char jewel: jewels) {
            map[jewel] = 1;
        }
        for (char stone: stones) {
            if (map[stone]) {
                res++;
            }
        }
        return res;
    }
};