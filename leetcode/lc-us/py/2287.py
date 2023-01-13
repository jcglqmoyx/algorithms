from collections import Counter


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cnt1, cnt2 = Counter(s), Counter(target)
        res = float('inf')
        for key, value in cnt2.items():
            res = min(res, cnt1[key] // value)
        return res
