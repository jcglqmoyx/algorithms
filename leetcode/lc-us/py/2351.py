class Solution:
    def repeatedCharacter(self, s: str) -> str:
        S = set()
        for c in s:
            if c in S:
                return c
            S.add(c)
