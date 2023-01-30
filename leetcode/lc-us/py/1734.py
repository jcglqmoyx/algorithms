from typing import List


class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1

        total = n % 4 == 1

        odd = 0
        for i in range(1, n - 1, 2):
            odd ^= encoded[i]

        res = [total ^ odd] + [0] * (n - 1)
        for i in range(1, n):
            res[i] = res[i - 1] ^ encoded[i - 1]

        return res
