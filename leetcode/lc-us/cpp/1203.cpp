#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        int count_group = m;
        vector<int> group_id(n);
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group_id[i] = count_group++;
            } else {
                group_id[i] = group[i];
            }
        }
        vector<vector<int>> ne(count_group);
        vector<int> group_degree(count_group);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                int before_item = beforeItems[i][j];
                int before_group = group_id[before_item];
                int current_group = group_id[i];
                if (before_group == current_group) continue;
                ne[before_group].push_back(current_group);
                group_degree[current_group]++;
            }
        }
        vector<int> sorted_groups;
        queue<int> q;
        for (int i = 0; i < count_group; i++) {
            if (group_degree[i] == 0) {
                q.push(i);
                sorted_groups.push_back(i);
            }
        }
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int x: ne[t]) {
                    if (--group_degree[x] == 0) {
                        q.push(x);
                        sorted_groups.push_back(x);
                    }
                }
            }
        }
        if (sorted_groups.size() != count_group) return {};

        vector<int> item_degree(n);
        vector<vector<int>> group_items(count_group);
        for (int i = 0; i < n; i++) {
            group_items[group_id[i]].push_back(i);
        }

        ne.clear();
        ne.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                int before_item = beforeItems[i][j];
                int before_group = group_id[before_item];
                int current_group = group_id[i];
                if (before_group == current_group) {
                    item_degree[i]++;
                    ne[before_item].push_back(i);
                }
            }
        }

        vector<int> res;
        for (int g: sorted_groups) {
            int cnt = 0;
            while (!q.empty()) q.pop();
            for (int item: group_items[g]) {
                if (item_degree[item] == 0) {
                    q.push(item);
                    res.push_back(item);
                    cnt++;
                }
            }
            while (!q.empty()) {
                for (auto it = q.size(); it; it--) {
                    int t = q.front();
                    q.pop();
                    for (int x: ne[t]) {
                        if (--item_degree[x] == 0) {
                            q.push(x);
                            res.push_back(x);
                            cnt++;
                        }
                    }
                }
            }
            if (cnt != group_items[g].size()) return {};
        }
        return res;
    }
};
