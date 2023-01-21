from typing import List


class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        a, b, c = 1, 0, 1
        for i in range(1, len(obstacles)):
            o = obstacles[i]
            a1 = b1 = c1 = float('inf')
            if o == 1:
                b1, c1 = min(b, c + 1), min(c, b + 1)
            elif o == 2:
                a1, c1 = min(a, c + 1), min(c, a + 1)
            elif o == 3:
                a1, b1 = min(a, b + 1), min(b, a + 1)
            else:
                a1, b1, c1 = min(a, b + 1, c + 1), min(b, a + 1, c + 1), min(c, a + 1, b + 1)
            a, b, c = a1, b1, c1
        return min(a, b, c)
