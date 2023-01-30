class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 1:
            return n
        if n == 2:
            return 1
        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            t = c
            c = a + b + c
            a = b
            b = t
        return c
