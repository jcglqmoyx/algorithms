class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        v = ['' for _ in range(numRows)]
        row, dt = 0, 1
        for i in range(len(s)):
            v[row] += s[i]
            row += dt
            if row == 0 or row == numRows - 1:
                dt = -dt
        return ''.join(v)
