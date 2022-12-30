class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        LL l = 2, r = 1e6;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            if (check(mid / 2, neededApples)) r = mid;
            else l = mid + 1;
        }
        return l * 4;
    }

private:
    using LL = long long;

    static bool check(LL len, LL tot) {
        return len * (2 * len * len + 3 * len + 1) * 2 >= tot;
    }
};