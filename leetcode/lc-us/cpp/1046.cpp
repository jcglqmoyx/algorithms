#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> q;
        for (int stone: stones) {
            q.push(stone);
        }
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            if (q.empty()) {
                return x;
            } else {
                int y = q.top();
                q.pop();
                if (x != y) {
                    q.push(x - y);
                }
            }
        }
        return 0;
    }
};