from typing import List


class Solution:
    def possibleToStamp(self, grid: List[List[int]], h: int, w: int) -> bool:
        n, m = len(grid), len(grid[0])
        s = [[0] * (m + 1) for _ in range(n + 1)]
        diff = [[0] * (m + 2) for _ in range(n + 2)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1]
        for i in range(1, n - h + 2):
            for j in range(1, m - w + 2):
                if s[i + h - 1][j + w - 1] - s[i + h - 1][j - 1] - s[i - 1][j + w - 1] + s[i - 1][j - 1] == 0:
                    diff[i][j] += 1
                    diff[i + h][j] -= 1
                    diff[i][j + w] -= 1
                    diff[i + h][j + w] += 1

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]
                if grid[i - 1][j - 1] == 0 and diff[i][j] == 0:
                    return False
        return True
