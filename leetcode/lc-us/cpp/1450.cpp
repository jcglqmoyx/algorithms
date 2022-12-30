#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        int busy_student = 0;
        for (int i = 0; i < startTime.size(); i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                busy_student++;
            }
        }
        return busy_student;
    }
};