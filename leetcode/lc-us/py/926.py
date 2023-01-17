"""
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        cnt = [0] * (n + 1)
        for i in range(1, n + 1):
            cnt[i] = cnt[i - 1] + (s[i - 1] == '1')

        res = min(cnt[n], n - cnt[n])
        for i in range(1, n + 1):
            res = min(res, cnt[i] + n - i - (cnt[n] - cnt[i]))
        return res
"""


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        min_diff = cnt1 = 0
        for c in s:
            if c == '1':
                cnt1 += 1
            elif cnt1 > min_diff:
                min_diff += 1
        return min_diff
