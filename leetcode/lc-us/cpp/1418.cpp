#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        vector<vector<string>> display_table = {{"Table"}};
        unordered_map<string, unordered_map<string, int>> map;
        unordered_set<string> tables;
        unordered_set<string> items;
        for (const vector<string> &order: orders) {
            map[order[1]][order[2]]++;
            tables.insert(order[1]);
            items.insert(order[2]);
        }
        vector<string> table_list(tables.begin(), tables.end()), item_list(items.begin(), items.end());
        sort(table_list.begin(), table_list.end(), [](const string &a, const string &b) {
            return stoi(a) < stoi(b);
        });
        sort(item_list.begin(), item_list.end());
        for (const string &item: item_list) {
            display_table[0].push_back(item);
        }
        for (auto &e: table_list) {
            display_table.push_back({e});
            for (int j = 0; j < items.size(); j++) {
                display_table.back().push_back(to_string(map[e][item_list[j]]));
            }
        }
        return display_table;
    }
};