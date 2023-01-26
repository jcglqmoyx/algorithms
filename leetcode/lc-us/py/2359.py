from typing import List


class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        if node1 == node2:
            return node1
        n = len(edges)

        def f(p: int) -> List[int]:
            dist = [n] * n
            d = 0
            while p != -1 and dist[p] == n:
                dist[p] = d
                d += 1
                p = edges[p]
            return dist

        d1, d2 = f(node1), f(node2)
        res, mn = -1, n
        for i in range(n - 1, -1, -1):
            t = max(d1[i], d2[i])
            if t <= mn:
                mn, res = t, i
        return -1 if mn == n else res
