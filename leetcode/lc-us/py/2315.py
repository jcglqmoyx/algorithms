class Solution:
    def countAsterisks(self, s: str) -> int:
        res = bar = 0
        for c in s:
            if c == '|':
                bar += 1
            elif c == '*' and bar % 2 == 0:
                res += 1
        return res
