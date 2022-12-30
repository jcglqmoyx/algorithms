#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = (int) boxes.size();
        vector<int> p(n + 1), w(n + 1), neg(n + 2);
        vector<long long> W(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = boxes[i - 1][0], w[i] = boxes[i - 1][1];
            W[i] = W[i - 1] + w[i];
            if (i > 1) neg[i] = neg[i - 1] + (p[i] != p[i - 1]);
        }
        vector<int> f(n + 1), g(n + 1);
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (i - dq.front() > maxBoxes || W[i] - W[dq.front()] > maxWeight) dq.pop_front();
            f[i] = g[dq.front()] + neg[i] + 2;
            g[i] = f[i] - neg[i + 1];
            while (!dq.empty() && g[i] <= g[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return f[n];
    }
};