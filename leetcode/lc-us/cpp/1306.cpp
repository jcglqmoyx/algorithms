#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = (int) arr.size();
        vector<bool> st(n);
        st[start] = true;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (t + arr[t] < n && !st[t + arr[t]]) {
                q.push(t + arr[t]);
                st[t + arr[t]] = true;
            }
            if (t - arr[t] >= 0 && !st[t - arr[t]]) {
                q.push(t - arr[t]);
                st[t - arr[t]] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && st[i]) {
                return true;
            }
        }
        return false;
    }
};