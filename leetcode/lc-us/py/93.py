from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        ip = ''

        def dfs(u: int, x: int, cnt: int, i: int) -> None:
            if cnt > 4:
                return
            nonlocal ip
            if u == len(s):
                if cnt == 4 and i == u:
                    res.append(ip)
            else:
                d = int(s[u])
                num = x * 10 + d
                if num <= 255:
                    flag = 0
                    if ip:
                        ip += '.'
                        flag = 1
                    ip += str(num)
                    dfs(u + 1, 0, cnt + 1, u + 1)
                    ip = ip[:len(ip) - len(str(num)) - flag]

                    if num:
                        dfs(u + 1, num, cnt, i)

        dfs(0, 0, 0, 0)
        return res
