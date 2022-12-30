#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        using LL = long long;

        int res = 0;
        LL sum = 0;
        deque<int> q;
        for (int i = 0, j = 0; j < chargeTimes.size(); j++) {
            while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[j]) q.pop_back();
            sum += runningCosts[j];
            q.push_back(j);
            while (i <= j && chargeTimes[q.front()] + sum * 1LL * (j - i + 1) > budget) {
                sum -= runningCosts[i];
                if (i == q.front()) q.pop_front();
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};