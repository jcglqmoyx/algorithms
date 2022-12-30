#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> map;
        for (char t: tasks) map[t]++;
        int max_c = 0;
        for (auto[task, count]: map) {
            max_c = max(max_c, count);
        }
        int cnt = 0;
        for (auto[task, count]: map) {
            if (count == max_c) {
                cnt++;
            }
        }
        return max((int) tasks.size(), (max_c - 1) * (n + 1) + cnt);
    }
};