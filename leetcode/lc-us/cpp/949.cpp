#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int> &arr) {
        int time = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    for (int k = 0; k < 4; k++) {
                        if (k != j && k != i) {
                            int l = 6 - i - j - k;
                            int hour = arr[i] * 10 + arr[j], minute = arr[k] * 10 + arr[l];
                            if (hour < 24 && minute < 60) {
                                time = max(time, hour * 60 + minute);
                            }
                        }
                    }
                }
            }
        }
        if (time == -1) return "";
        int hour = time / 60, minute = time % 60;
        string res;
        res += hour < 10 ? "0" + to_string(hour) : to_string(hour);
        res += ':';
        res += minute < 10 ? "0" + to_string(minute) : to_string(minute);
        return res;
    }
};