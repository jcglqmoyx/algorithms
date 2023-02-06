from collections import Counter, defaultdict

from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cp = Counter(p)
        cs = defaultdict(int)
        res = []
        i = j = 0
        while j < len(s):
            cs[s[j]] += 1
            while cs[s[j]] > cp[s[j]]:
                cs[s[i]] -= 1
                i += 1
            if j - i + 1 == len(p):
                res.append(i)
            j += 1
        return res
