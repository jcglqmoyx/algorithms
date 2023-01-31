from typing import List


class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        n, m = len(matrix), len(matrix[0])
        s = [[0] * (m + 1) for _ in range(n + 1)]
        v = []
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                s[i][j] = s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1] ^ matrix[i - 1][j - 1]
                v.append(s[i][j])
        return sorted(v, reverse=True)[k - 1]
