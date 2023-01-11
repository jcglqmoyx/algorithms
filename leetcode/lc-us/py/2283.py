from collections import Counter


class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = Counter(num)
        for idx, c in enumerate(num):
            if int(c) != cnt[str(idx)]:
                return False
        return True
