import math


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        max_len = math.gcd(n, m)

        def valid(length: int) -> bool:
            for i in range(0, n - length + 1, length):
                if str1[i: i + length] != str1[0: length]:
                    return False
            for i in range(0, m - length + 1, length):
                if str2[i:i + length] != str1[0:length]:
                    return False
            return True

        for length in range(max_len, 0, -1):
            if n % length or m % length:
                continue
            if valid(length):
                return str1[:length]
        return ''
