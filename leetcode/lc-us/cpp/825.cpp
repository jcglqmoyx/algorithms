#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        int map[121] = {};
        for (int age: ages) map[age]++;
        int res = 0;
        for (int i = 1; i <= 120; i++) {
            for (int j = 1; j <= i; j++) {
                if (j <= 0.5 * i + 7) continue;
                res += map[i] * map[j];
                if (i == j) res -= map[i];
            }
        }
        return res;
    }
};