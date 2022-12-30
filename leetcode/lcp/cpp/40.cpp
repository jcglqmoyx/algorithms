#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

class Solution {
public:
    int maxmiumScore(vector<int> &a, int cnt) {
        priority_queue<int, VI, greater<>> oe, ee;
        priority_queue<int> odd, even;
        for (int num: a) {
            if (num & 1) odd.push(num);
            else even.push(num);
        }
        int tot = 0;
        while (!odd.empty() || !even.empty()) {
            if (!odd.empty() && !even.empty()) {
                int s = odd.top(), t = even.top();
                if (s > t) odd.pop(), tot += s, oe.push(s);
                else even.pop(), tot += t, ee.push(t);
            } else if (!odd.empty()) {
                int s = odd.top();
                odd.pop(), tot += s, oe.push(s);
            } else {
                int t = even.top();
                even.pop(), tot += t, ee.push(t);
            }
            if (oe.size() + ee.size() == cnt) break;
        }
        if (!(tot & 1)) return tot;
        int res = 0;
        if (!even.empty()) res = max(res, tot - oe.top() + even.top());
        if (!odd.empty() && !ee.empty()) res = max(res, tot - ee.top() + odd.top());
        if (!(res & 1)) return res;
        else return 0;
    }
};