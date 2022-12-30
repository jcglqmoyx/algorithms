#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students) {
        int res = 0;
        sort(seats.begin(), seats.end()), sort(students.begin(), students.end());
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
        return res;
    }
};