#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int get(string &s) {
        int res = 0;
        int m = stoi(s.substr(0, 2)), d = stoi(s.substr(3));
        for (int i = 0; i < m - 1; i++) {
            res += DAYS[i];
        }
        res += d;
        return res;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return max(0, min(get(leaveAlice), get(leaveBob)) - max(get(arriveAlice), get(arriveBob)) + 1);
    }
};