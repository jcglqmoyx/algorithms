#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &target) {
        if (target.size() == 1 && target[0] != 1) return false;
        using ll = long long;
        priority_queue<ll> q;
        for (int x: target) q.push(x);
        ll sum = accumulate(target.begin(), target.end(), static_cast<ll>(0));
        while (q.top() > 1) {
            ll t = q.top();
            q.pop();
            ll left = sum - t;

            if (t <= left) return false;
            ll p = t;
            if (t % left == 0) t = left;
            else t %= left;
            ll diff = p - t;
            sum -= diff;

            if (t < 1) return false;
            q.push(t);
        }
        return true;
    }
};