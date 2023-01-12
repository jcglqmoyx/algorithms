from typing import List


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        d = dict(knowledge)
        res = ''
        i = 0
        while i < len(s):
            if s[i] == '(':
                j = i + 1
                while j < len(s) and s[j] != ')':
                    j += 1
                key = s[i + 1:j]
                if key in d:
                    res += d[key]
                else:
                    res += '?'
                i = j
            else:
                res += s[i]
            i += 1
        return res
