#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;
using PII = pair<int, int>;
using VPII = vector<pair<int, int>>;
using VVI = vector<vector<int>>;
using USI = unordered_set<int>;
using UMII = unordered_map<int, int>;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define per(i, a, b) for (int (i) = (a); (i) > (b); (i)--)

const int MOD = 1e9 + 7;

template<typename T>
class BIT {
    vector<T> tree;
public:
    explicit BIT(T n) : tree(n) {}

    int low_bit(int x) {
        return x & -x;
    }

    void update(int x, T dt) {
        while (x < tree.size()) tree[x] += dt, x += low_bit(x);
    }

    T query(int x) {
        T res = 0;
        while (x) res += tree[x], x -= low_bit(x);
        return res;
    }
};