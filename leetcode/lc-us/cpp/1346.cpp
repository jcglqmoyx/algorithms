#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        int count[2001] = {};
        for (int num: arr) {
            count[num + 1000]++;
        }
        if (count[1000] >= 2) {
            return true;
        }
        for (int i = -500; i < 0; i++) {
            if (count[i + 1000] && count[2 * i + 1000]) {
                return true;
            }
        }
        for (int i = 1; i <= 500; i++) {
            if (count[i + 1000] && count[2 * i + 1000]) {
                return true;
            }
        }
        return false;
    }
};