#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int> &arr) {
        int count[501] = {};
        for (int num: arr) {
            count[num]++;
        }
        for (int i = 500; i >= 1; i--) {
            if (count[i] == i) {
                return i;
            }
        }
        return -1;
    }
};