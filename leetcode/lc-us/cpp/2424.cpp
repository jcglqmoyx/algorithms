class LUPrefix {
    int sz;
    int tr[100005];

    int low_bit(int x) {
        return x & -x;
    }

    void update(int x, int dt) {
        while (x <= sz) tr[x] += dt, x += low_bit(x);
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    LUPrefix(int n) {
        sz = n;
        for (int i = 0; i <= sz; i++) tr[i] = 0;
    }

    void upload(int video) {
        update(video, 1);
    }

    int longest() {
        int l = 0, r = sz;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (query(mid) == mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};