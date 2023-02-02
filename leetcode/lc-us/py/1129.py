from collections import defaultdict

from typing import List


class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        for e in redEdges:
            g[e[0]].append((e[1], 0))
        for e in blueEdges:
            g[e[0]].append((e[1], 1))
        r, b = [0] + [-1] * (n - 1), [0] + [-1] * (n - 1)
        q = [(0, 0), (0, 1)]
        while q:
            t = q[0]
            q = q[1:]
            p, c = t
            for ne in g[p]:
                if c == 0:
                    if ne[1] == 1 and (b[ne[0]] == -1 or b[ne[0]] > r[p] + 1):
                        b[ne[0]] = r[p] + 1
                        q.append((ne[0], 1))
                else:
                    if ne[1] == 0 and (r[ne[0]] == -1 or r[ne[0]] > b[p] + 1):
                        r[ne[0]] = b[p] + 1
                        q.append((ne[0], 0))
        res = [-1] * n
        for i in range(n):
            if r[i] == b[i] == -1:
                continue
            elif r[i] == -1:
                res[i] = b[i]
            elif b[i] == -1:
                res[i] = r[i]
            else:
                res[i] = min(r[i], b[i])
        return res
