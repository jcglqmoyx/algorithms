#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        auto *node = new Trie();
        m = (int) board.size(), n = (int) board[0].size();
        for (int i = 0; i < words.size(); i++) {
            node->insert(words[i], i);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, node->next[board[i][j] - 'a']);
            }
        }
        vector<string> res;
        for (int id: ids) {
            res.push_back(words[id]);
        }
        return res;
    }

private:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int m, n;
    unordered_set<int> ids;

    struct Trie {
        int id;
        Trie *next[26]{};

        Trie() : id(-1), next() {}

        void insert(string &w, int index) {
            Trie *trie = this;
            for (char c: w) {
                int u = c - 'a';
                if (!trie->next[u]) trie->next[u] = new Trie();
                trie = trie->next[u];
            }
            trie->id = index;
        }
    };

    void dfs(vector<vector<char>> &board, int x, int y, Trie *node) {
        if (!node) return;
        if (node->id != -1) {
            ids.insert(node->id);
        }
        char tmp = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] != '.' && node->next[board[a][b] - 'a']) {
                dfs(board, a, b, node->next[board[a][b] - 'a']);
            }
        }
        board[x][y] = tmp;
    }
};