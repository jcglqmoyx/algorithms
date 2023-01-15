from typing import List


class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff = [[0] * (n + 2) for _ in range(n + 2)]

        for q in queries:
            x1, y1, x2, y2 = q[0] + 1, q[1] + 1, q[2] + 1, q[3] + 1
            diff[x1][y1] += 1
            diff[x1][y2 + 1] -= 1
            diff[x2 + 1][y1] -= 1
            diff[x2 + 1][y2 + 1] += 1
        res = [[0] * n for _ in range(n)]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]
                res[i - 1][j - 1] = diff[i][j]
        return res
