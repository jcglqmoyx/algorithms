from collections import Counter


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        cnt = Counter(s)
        if k and len(cnt) < 3:
            return -1
        for _, freq in cnt.items():
            if freq < k:
                return -1
        res = n + 1
        i, j = 0, 0
        while j < n:
            c = s[j]
            cnt[c] -= 1
            while cnt[c] < k:
                cnt[s[i]] += 1
                i += 1
            res = min(res, n - (j - i + 1))
            j += 1
        return -1 if res > n else res
