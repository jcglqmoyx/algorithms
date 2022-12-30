#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<bool> keys;

    void dfs(const vector<vector<int>> &rooms, int i) {
        keys[i] = true;
        for (int key: rooms[i]) {
            if (!keys[key]) {
                keys[key] = true;
                dfs(rooms, key);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = (int) rooms.size();
        keys.resize(n);
        keys[0] = true;
        for (int i = 0; i < rooms[0].size(); i++) {
            dfs(rooms, rooms[0][i]);
        }
        for (int i = 1; i < n; i++) {
            if (!keys[i]) return false;
        }
        return true;
    }
};