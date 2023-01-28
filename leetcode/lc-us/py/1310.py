from typing import List


class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        s = [0] * (n + 1)
        for i in range(1, n + 1):
            s[i] = s[i - 1] ^ arr[i - 1]
        res = []
        for q in queries:
            res.append(s[q[1] + 1] ^ s[q[0]])
        return res
