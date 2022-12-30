#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &ticket: tickets) {
            m[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

private:
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> m;
    vector<string> res;

    void dfs(const string &ticket) {
        while (m.find(ticket) != m.end() && !m[ticket].empty()) {
            string destination = m[ticket].top();
            m[ticket].pop();
            dfs(destination);
        }
        res.push_back(ticket);
    }
};