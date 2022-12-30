#include <bits/stdc++.h>

using namespace std;

class BookMyShow {
    int n, m;
    vector<long long> sum_tree;
    vector<int> max_tree;

    void build(int pos, int l, int r) {
        if (l > r) return;
        if (l == r) {
            sum_tree[pos] = max_tree[pos] = m;
            return;
        }

        int mid = (l + r) >> 1;
        build(pos * 2, l, mid);
        build(pos * 2 + 1, mid + 1, r);

        sum_tree[pos] = sum_tree[pos * 2] + sum_tree[pos * 2 + 1];
        max_tree[pos] = max(max_tree[pos * 2], max_tree[pos * 2 + 1]);
    }

    void update(int pos, int l, int r, int row, int value) {
        if (r < row || row < l) return;
        if (l == r) {
            sum_tree[pos] = max_tree[pos] = value;
            return;
        }

        int mid = (l + r) >> 1;
        update(pos * 2, l, mid, row, value);
        update(pos * 2 + 1, mid + 1, r, row, value);

        sum_tree[pos] = sum_tree[pos * 2] + sum_tree[pos * 2 + 1];
        max_tree[pos] = max(max_tree[pos * 2], max_tree[pos * 2 + 1]);
    }

    pair<int, int> getMinRow(int pos, int l, int r, int L, int R, int k) {
        if (r < L || R < l) return {n, 0};

        int mid = (l + r) >> 1;
        if (L <= l && r <= R) {
            if (l == r) {
                return {l, max_tree[pos]};
            }

            if (max_tree[pos * 2] < k) {
                return getMinRow(pos * 2 + 1, mid + 1, r, L, R, k);
            } else {
                return getMinRow(pos * 2, l, mid, L, R, k);
            }
        }

        auto left = getMinRow(pos * 2, l, mid, L, R, k);
        auto right = getMinRow(pos * 2 + 1, mid + 1, r, L, R, k);

        if (left.second >= k) {
            return left;
        } else if (right.second >= k) {
            return right;
        } else {
            return {n, 0};
        }
    }

    long long int getSum(int pos, int l, int r, int L, int R) {
        if (r < L || R < l) return 0;
        if (L <= l && r <= R) {
            return sum_tree[pos];
        }

        int mid = (l + r) >> 1;
        return getSum(pos * 2, l, mid, L, R) + getSum(pos * 2 + 1, mid + 1, r, L, R);
    }

public:
    BookMyShow(int n, int m) : n(n), m(m) {
        sum_tree.assign(n * 4, 0);
        max_tree.assign(n * 4, 0);
        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow) {
        const auto p = getMinRow(1, 0, n - 1, 0, maxRow, k);
        if (p.first > maxRow || p.second < k) {
            return {};
        }

        const int r = p.first;
        const int c = m - p.second;

        update(1, 0, n - 1, r, p.second - k);
        return vector<int>({r, c});
    }

    bool scatter(int k, int maxRow) {
        const auto totalSitInRange = getSum(1, 0, n - 1, 0, maxRow);
        if (totalSitInRange < k) return false;

        int r = 0, c;
        while (k) {
            auto p = getMinRow(1, 0, n - 1, r, maxRow, 1);

            c = min(k, p.second);
            k -= c;
            update(1, 0, n - 1, p.first, p.second - c);

            r = p.first + 1;
        }
        return true;
    }
};