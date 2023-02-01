class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        d = {}
        letter = 'a'
        for c in key:
            if c != ' ' and c not in d:
                d[c] = letter
                letter = chr(ord(letter) + 1)
        res = ''
        for c in message:
            if c == ' ':
                res += ' '
            else:
                res += d[c]
        return res
