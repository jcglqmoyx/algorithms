#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &arr) {
        int count = 0;
        int map[1002] = {};
        for (int num: arr) {
            map[num]++;
        }
        for (int num: arr) {
            if (map[num + 1]) {
                count++;
            }
        }
        return count;
    }
};