#include <bits/stdc++.h>

using namespace std;

class Solution {
    int old_color;

    void dfs(vector<vector<int>> &image, int sr, int sc, int new_color) {
        if (sr < 0 || sr == (int) image.size() || sc < 0 || sc == (int) image[0].size() || image[sr][sc] == new_color ||
            image[sr][sc] != old_color) {
            return;
        }
        image[sr][sc] = new_color;
        dfs(image, sr - 1, sc, new_color);
        dfs(image, sr + 1, sc, new_color);
        dfs(image, sr, sc - 1, new_color);
        dfs(image, sr, sc + 1, new_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        old_color = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};