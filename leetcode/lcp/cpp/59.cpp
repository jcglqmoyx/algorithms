#include <bits/stdc++.h>

using namespace std;

class Solution {
    priority_queue<long long> L;
    priority_queue<long long, vector<long long>, greater<long long>> R;

public:
    long long buildBridge(int num, vector<vector<int>> &wood) {
        L.push(wood[0][0]);
        R.push(wood[0][0]);
        long long biasL = 0, biasR = 0, ans = 0;
        for (int i = 1; i < wood.size(); i++) {
            biasL -= wood[i][1] - wood[i][0];
            biasR += wood[i - 1][1] - wood[i - 1][0];
            long long l0 = L.top() + biasL;
            long long r0 = R.top() + biasR;
            int x = wood[i][0];
            if (x < l0) {
                ans += l0 - x;
                L.pop();
                L.push(x - biasL);
                L.push(x - biasL);
                R.push(l0 - biasR);
            } else if (x > r0) {
                ans += x - r0;
                R.pop();
                R.push(x - biasR);
                R.push(x - biasR);
                L.push(r0 - biasL);
            } else {
                L.push(x - biasL);
                R.push(x - biasR);
            }
        }
        return ans;
    }
};