from typing import List


class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        res = 0
        pre = 0
        for bracket in brackets:
            upper, percent = bracket
            if upper <= income:
                res += (upper - pre) * percent / 100
            else:
                res += (income - pre) * percent / 100
                break
            pre = upper
        return res
