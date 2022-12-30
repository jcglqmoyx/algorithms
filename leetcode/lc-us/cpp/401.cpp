#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (bit_count(minute) + bit_count(hour) == num) {
                    string time;
                    time += to_string(hour) + ":";
                    time += minute > 9 ? to_string(minute) : "0" + to_string(minute);
                    res.push_back(time);
                }
            }
        }
        return res;
    }

private:
    int bit_count(int num) {
        int bits = 0;
        while (num) {
            if ((num & 1) == 1) {
                bits++;
            }
            num >>= 1;
        }
        return bits;
    }
};