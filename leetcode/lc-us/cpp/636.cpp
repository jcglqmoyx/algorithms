#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n);
        stack<int> stk;
        int last;
        for (auto &log: logs) {
            size_t x = log.find(':'), y = log.rfind(':');
            int id = stoi(log.substr(0, x)), timestamp = stoi(log.substr(y + 1));
            char op = log[x + 1];
            if (op == 's') {
                if (!stk.empty()) res[stk.top()] += timestamp - last;
                stk.push(id);
                last = timestamp;
            } else if (op == 'e') {
                res[stk.top()] += timestamp - last + 1;
                stk.pop();
                last = timestamp + 1;
            }
        }
        return res;
    }
};