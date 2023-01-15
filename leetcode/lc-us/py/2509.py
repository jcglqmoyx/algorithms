from typing import List


class Solution:
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        res = [0] * len(queries)
        for i in range(len(queries)):
            x, y = queries[i]
            t = 1
            while x != y:
                if x > y:
                    x >>= 1
                else:
                    y >>= 1
                t += 1
            res[i] = t
        return res
