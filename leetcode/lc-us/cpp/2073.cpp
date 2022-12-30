#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int res = 0;
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) res += min(tickets[i], tickets[k]);
            else res += min(tickets[i], tickets[k] - 1);
        }
        return res;
    }
};