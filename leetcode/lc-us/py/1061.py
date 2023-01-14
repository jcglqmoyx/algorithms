class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        p = [i for i in range(26)]

        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        for i in range(len(s1)):
            a, b = ord(s1[i]) - ord('a'), ord(s2[i]) - ord('a')
            pa, pb = find(a), find(b)
            if pa > pb:
                p[pa] = pb
            else:
                p[pb] = pa

        res = ''
        for c in baseStr:
            res += chr(find(ord(c) - ord('a')) + ord('a'))
        return res
