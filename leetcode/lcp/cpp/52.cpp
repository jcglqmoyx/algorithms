#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int N = 100010;
const char BLUE = 'B', RED = 'R';

struct Node {
    int l, r;
    int red, blue;
    char change;
} tr[N << 2];

void push_up(int u) {
    tr[u].red = tr[u << 1].red + tr[u << 1 | 1].red;
    tr[u].blue = tr[u << 1].blue + tr[u << 1 | 1].blue;
}

void push_down(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.change) {
        left.change = root.change, right.change = root.change;
        if (root.change == BLUE) {
            left.red = 0, left.blue = left.r - left.l + 1;
            right.red = 0, right.blue = right.r - right.l + 1;
        } else {
            left.red = left.r - left.l + 1, left.blue = 0;
            right.red = right.r - right.l + 1, right.blue = 0;
        }
        root.change = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, 0, 1, 0};
    } else {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int l, int r, char c) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (c == BLUE) {
            tr[u].blue = tr[u].r - tr[u].l + 1;
            tr[u].red = 0;
        } else {
            tr[u].red = tr[u].r - tr[u].l + 1;
            tr[u].blue = 0;
        }
        tr[u].change = c;
    } else {
        push_down(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r, c);
        if (r > mid) modify(u << 1 | 1, l, r, c);
        push_up(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].red;
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

class Solution {
public:
    vector<int> v;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    int get(int x) {
        int l = 0, r = (int) v.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (v[mid] < x) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int getNumber(TreeNode *root, vector<vector<int>> &ops) {
        dfs(root);
        int n = (int) v.size();
        build(1, 1, n);
        for (auto &op: ops) {
            int c = op[0], start = get(op[1]) + 1, end = get(op[2]) + 1;
            char new_color = c ? RED : BLUE;
            modify(1, start, end, new_color);
        }
        return query(1, 1, n);
    }
};