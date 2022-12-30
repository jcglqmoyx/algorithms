#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_set<int> s;
        for (int i = 0; (int) pow(x, i) <= bound - 1; i++) {
            for (int j = 0; (int) pow(y, j) <= bound - 1; j++) {
                int value = (int) pow(x, i) + (int) pow(y, j);
                if (value <= bound) {
                    s.insert(value);
                } else {
                    break;
                }
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        res.reserve(s.size());
        for (int num: s) {
            res.push_back(num);
        }
        return res;
    }
};