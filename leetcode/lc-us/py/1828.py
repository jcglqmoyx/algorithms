from typing import List


class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res = []
        for x, y, r in queries:
            res.append(sum((x - a) ** 2 + (y - b) ** 2 <= r ** 2 for a, b in points))
        return res
