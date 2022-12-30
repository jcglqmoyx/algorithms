#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        using PCI = pair<char, int>;

        string res;
        priority_queue<PCI> pq;
        unordered_map<char, int> cnt;
        for (char c: s) cnt[c]++;
        for (auto[c, freq]: cnt) pq.push({c, freq});
        while (!pq.empty()) {
            if (res.empty() || res.back() != pq.top().first) {
                auto t = pq.top();
                pq.pop();
                char c = t.first;
                int f = t.second;
                int x = min(f, repeatLimit);
                for (int i = 0; i < x; i++) {
                    res.push_back(c);
                }
                f -= x;
                if (f) pq.push({c, f});
            } else {
                auto t1 = pq.top();
                pq.pop();
                if (pq.empty()) break;
                auto t2 = pq.top();
                pq.pop();
                res.push_back(t2.first);
                t2.second--;
                pq.push(t1);
                if (t2.second) pq.push(t2);
            }
        }
        return res;
    }
};