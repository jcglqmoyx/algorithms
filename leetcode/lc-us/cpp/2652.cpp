class Solution {
public:
    int sumOfMultiples(int n) {
        auto calc = [&](int x) {
            int cnt = n / x;
            int l = x, r = cnt * x;
            return (l + r) * cnt / 2;
        };
        return calc(3) + calc(5) + calc(7) - calc(15) - calc(21) - calc(35) + calc(105);
    }
};