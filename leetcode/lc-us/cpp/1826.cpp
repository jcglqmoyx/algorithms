#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int badSensor(vector<int> &sensor1, vector<int> &sensor2) {
        int drop = 0;
        for (int i = 0; i < sensor1.size(); i++) {
            if (sensor1[i] != sensor2[i]) {
                drop = i;
                break;
            }
        }
        bool left_drop = true, right_drop = true;
        for (int i = drop + 1; i < sensor1.size(); i++) {
            if (sensor1[i] != sensor2[i - 1]) {
                right_drop = false;
            }
            if (sensor2[i] != sensor1[i - 1]) {
                left_drop = false;
            }
        }
        if (left_drop && !right_drop) {
            return 1;
        }
        if (right_drop && !left_drop) {
            return 2;
        }
        return -1;
    }
};