#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        using PIC = pair<int, char>;
        if (k == 0) return s;
        int n = (int) s.size();
        int cnt[123] = {0};
        for (char c: s) cnt[c]++;
        priority_queue<PIC> heap;
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c]) {
                heap.emplace(cnt[c], c);
            }
        }
        string res(n, 'a');
        queue<PIC> q;
        int idx = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            res[idx++] = t.second;
            q.push({t.first - 1, t.second});
            if (q.size() == k) {
                for (int i = 0; i < k; i++) {
                    if (q.front().first) heap.push(q.front());
                    q.pop();
                }
            }
        }
        return idx < n ? "" : res;
    }
};