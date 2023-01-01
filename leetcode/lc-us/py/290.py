class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(pattern) != len(words):
            return False
        a, b = {}, {}
        for i in range(len(pattern)):
            x, y = pattern[i], words[i]
            if x in a and a[x] != y or y in b and b[y] != x:
                return False
            a[x] = y
            b[y] = x
        return True
