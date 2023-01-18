from collections import defaultdict

from typing import List


class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        g = defaultdict(list)
        for e in edges:
            x, y = e
            g[x].append(y)
            g[y].append(x)

        parent = defaultdict(int)

        def dfs1(u: int, p: int) -> None:
            if p != -1:
                parent[u] = p
            for v in g[u]:
                if v != p:
                    dfs1(v, u)

        dfs1(0, -1)

        nodes_on_path = defaultdict(int)

        step = 0
        while bob:
            nodes_on_path[bob] = step
            step += 1
            bob = parent[bob]
        nodes_on_path[0] = step

        res = -10 ** 10

        def dfs2(u: int, p: int, w: int) -> None:
            t = 0
            if u in nodes_on_path:
                if len(nodes_on_path) & 1 and nodes_on_path[u] == nodes_on_path[0] // 2:
                    t = amount[u] // 2
                elif nodes_on_path[u] > nodes_on_path[0] // 2:
                    t = amount[u]
            else:
                t = amount[u]
            nonlocal res
            if len(g[u]) == 1 and u:
                res = max(res, w + t)
            for v in g[u]:
                if v != p:
                    dfs2(v, u, w + t)

        dfs2(0, -1, 0)

        return res
