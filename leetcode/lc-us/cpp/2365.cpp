#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int> &tasks, int space) {
        unordered_map<int, long long> map;
        long long now = 1;
        for (int t: tasks) {
            if (map.count(t) && map[t] + space + 1 > now) {
                now = map[t] + space + 1;
            }
            map[t] = now;
            now++;
        }
        return now - 1;
    }
};