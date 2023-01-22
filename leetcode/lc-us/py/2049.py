from collections import defaultdict

from typing import List


class Solution:
    def __init__(self):
        self.mx = 0
        self.res = 0

    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n, g = len(parents), defaultdict(list)
        for i in range(1, len(parents)):
            g[parents[i]].append(i)

        def dfs(u: int, p: int) -> int:
            cnt = 1
            product = 1
            for x in g[u]:
                if x != p:
                    t = dfs(x, u)
                    product *= t
                    cnt += t
            if n - cnt:
                product *= (n - cnt)
            if product > self.mx:
                self.mx = product
                self.res = 1
            elif product == self.mx:
                self.res += 1
            return cnt

        dfs(0, -1)
        return self.res
