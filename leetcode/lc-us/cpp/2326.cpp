#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode *head) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<int>> res(n, vector<int>(m, -1));
        int d = 0;
        for (int i = 0, j = 0; head; head = head->next) {
            res[i][j] = head->val;
            int a = i + dx[d], b = j + dy[d];
            if (a < 0 || a == n || b < 0 || b == m || res[a][b] != -1) {
                d = (d + 1) % 4;
                a = i + dx[d], b = j + dy[d];
            }
            i = a, j = b;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (res[i][j] == 1e8) {
                    res[i][j] = -1;
                }
            }
        }
        return res;
    }
};