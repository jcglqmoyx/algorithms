from typing import List


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(scores)
        v = sorted(zip(scores, ages), key=lambda x: (x[1], x[0]))
        f = [0] * n
        for i in range(n):
            f[i] = v[i][0]
            for j in range(0, i):
                if v[j][0] <= v[i][0] and v[j][1] < v[i][1] or v[j][1] == v[i][1]:
                    f[i] = max(f[i], f[j] + v[i][0])
        return max(f)
