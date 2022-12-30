#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        using PII = pair<int, int>;
        vector<int> cnt(k);
        priority_queue<PII, vector<PII>, greater<>> busy;
        set<int> idle;
        for (int i = 0; i < k; i++) idle.insert(i);
        int n = (int) arrival.size();
        for (int i = 0; i < n; i++) {
            int a = arrival[i], l = load[i];
            while (!busy.empty() && busy.top().first <= a) {
                idle.insert(busy.top().second);
                busy.pop();
            }
            if (idle.empty()) continue;
            auto it = idle.lower_bound(i % k);
            int id;
            if (it == idle.end()) {
                id = *idle.begin();
            } else {
                id = *it;
            }
            idle.erase(id);
            busy.push({a + l, id});
            cnt[id]++;
        }
        int mx = 0;
        for (int freq: cnt) mx = max(mx, freq);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};