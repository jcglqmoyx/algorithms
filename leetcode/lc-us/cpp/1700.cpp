#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        stack<int> S;
        queue<int> q;
        reverse(sandwiches.begin(), sandwiches.end());
        for (int x: sandwiches) S.push(x);
        for (int x: students) q.push(x);
        int s[2];
        s[0] = s[1] = 0;
        for (int x: students) s[x]++;
        while (!q.empty() && !S.empty() && s[S.top()] != 0) {
            if (q.front() != S.top()) {
                q.push(q.front());
                q.pop();
                continue;
            }
            s[q.front()]--;
            q.pop();
            S.pop();
        }
        return q.size();
    }
};