from collections import Counter
from collections import defaultdict


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt1 = Counter(s1)
        cnt2 = defaultdict(int)
        i = j = 0
        while j < len(s2):
            cnt2[s2[j]] += 1
            if j - i + 1 == len(s1):
                flag = True
                for k, v in cnt1.items():
                    if v != cnt2[k]:
                        flag = False
                if flag:
                    return True
                cnt2[s2[i]] -= 1
                i += 1
            j += 1
        return False
