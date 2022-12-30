#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minInteger(string num, int k) {
        n = (int) num.size();
        tr.resize(n + 1);

        vector<queue<int>> q(10);
        for (int i = 1; i <= n; i++) {
            q[num[i - 1] - '0'].push(i);
        }
        string res;
        for (int i = 1; i <= n; i++) {
            for (int d = 0; d <= 9; d++) {
                if (q[d].empty()) continue;
                int t = q[d].front();
                int p = t + query(t);
                if (p - i <= k) {
                    k -= p - i;
                    q[d].pop();
                    res.push_back((char) (d + '0'));
                    update(1, 1), update(t, -1);
                    break;
                }
            }
        }
        return res;
    }

private:
    int n;
    vector<int> tr;

    int low_bit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= low_bit(x);
        }
        return res;
    }

    void update(int x, int dt) {
        while (x <= n) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }
};