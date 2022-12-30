#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>> &room) {
        int d = 0;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = (int) room.size(), m = (int) room[0].size();
        int x = 0, y = 0;
        unordered_set<string> hash;
        int cnt = 0;
        while (true) {
            if (room[x][y] == 0) cnt++, room[x][y] = 2;
            string state = to_string(x) + '.' + to_string(y) + '.' + to_string(d);
            if (hash.count(state)) break;
            hash.insert(state);
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || room[a][b] == 1) d = (d + 1) % 4;
            else x = a, y = b;
        }
        return cnt;
    }
};