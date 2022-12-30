#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        int people_who_are_trusted[1001] = {};
        int people_who_trust_others[1001] = {};
        for (const vector<int> &t: trust) {
            people_who_are_trusted[t[1]]++;
            people_who_trust_others[t[0]]++;
        }
        for (int i = 1; i <= 1000; i++) {
            if (people_who_are_trusted[i] == n - 1) {
                if (!people_who_trust_others[i]) {
                    return i;
                }
            }
        }
        return -1;
    }
};