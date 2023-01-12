from collections import defaultdict

from typing import List


class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        g = [[] for _ in range(n)]
        for e in edges:
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])

        res = [1] * n

        def dfs(u: int, p: int) -> defaultdict[int]:
            cnt = defaultdict(int)
            cnt[labels[u]] += 1
            for x in g[u]:
                if x != p:
                    t = dfs(x, u)
                    for k, v in t.items():
                        cnt[k] += v
            res[u] = cnt[labels[u]]
            return cnt

        dfs(0, -1)
        return res
