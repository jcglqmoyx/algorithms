#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int max_duration = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > max_duration) {
                res = keysPressed[i];
                max_duration = duration;
            } else if (duration == max_duration && keysPressed[i] > res) {
                res = keysPressed[i];
            }
        }
        return res;
    }
};