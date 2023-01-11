from typing import List


class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        g = [[] for _ in range(n)]
        st = [False] * n
        for edge in edges:
            g[edge[0]].append(edge[1])
            g[edge[1]].append(edge[0])

        def dfs(u) -> list[int | bool]:
            res = [0, False]
            if hasApple[u]:
                res[1] = True
            st[u] = True
            for ne in g[u]:
                if not st[ne]:
                    t = dfs(ne)
                    if t[1]:
                        res[0] += t[0] + 2
                        res[1] = True
            return res

        return dfs(0)[0]
