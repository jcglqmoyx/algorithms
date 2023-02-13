class Solution:
    def countOdds(self, low: int, high: int) -> int:
        res = (high - low + 1) // 2
        if low & 1 and high & 1:
            res += 1
        return res
