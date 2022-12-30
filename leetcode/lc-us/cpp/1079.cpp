#include <bits/stdc++.h>

using namespace std;

class Solution {
    int ans;
    vector<bool> visited;

    void dfs(string &tiles) {
        for (int i = 0; i < tiles.size(); i++) {
            if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                ans++;
                dfs(tiles);
                visited[i] = false;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        ans = 0;
        sort(tiles.begin(), tiles.end());
        visited.resize(tiles.size(), false);
        dfs(tiles);
        return ans;
    }
};