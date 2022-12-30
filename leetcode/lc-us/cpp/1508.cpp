#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int MODULO = 1000000007;
    int n;
    vector<int> s, ss;

    int get_sum(int k) {
        int num = get_kth(k), sum = 0, count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && s[j] - s[i] < num) j++;
            j--;
            sum = (sum + ss[j] - ss[i] - s[i] * (j - i)) % MODULO;
            count += j - i;
        }
        return sum + num * (k - count);
    }

    int get_kth(int k) {
        int low = 0, high = s[n];
        while (low < high) {
            int mid = low + (high - low) / 2, count = get_count(mid);
            if (count < k) low = mid + 1; else high = mid;
        }
        return low;
    }

    int get_count(int x) {
        int count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && s[j] - s[i] <= x) j++;
            j--;
            count += j - i;
        }
        return count;
    }

public:
    int rangeSum(vector<int> &nums, int _n, int left, int right) {
        n = _n;
        s.resize(n + 1), ss.resize(n + 1);
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + nums[i], ss[i + 1] = ss[i] + s[i + 1];
        return (get_sum(right) - get_sum(left - 1)) % MODULO;
    }
};