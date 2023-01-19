class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        a = b = c = d = False
        for i in range(len(password)):
            if i and password[i] == password[i - 1]:
                return False
            if password[i].islower():
                a = True
            elif password[i].isupper():
                b = True
            elif password[i].isdigit():
                c = True
            elif password[i] in '!@#$%^&*()-+':
                d = True
        return a and b and c and d
