t = input()
p = input()
orders = list(map(int, input().split()))

def s2Ins1(s1, s2):
    if len(s2) > len(s1):
        return False
    i = 0
    for char in s1:
        if i < len(s2) and char == s2[i]:
            i += 1
    return i == len(s2)

def f(n):
    curr = ""
    removable = set()
    for i in range(n):
        removable.add(orders[i])
    for i in range(len(t)):
        if (i+1) not in removable:
            curr += t[i]
    return s2Ins1(curr, p)
        


l = -1
r = len(orders)

while l+1 < r:
    m = (l+r)//2
    if f(m):
        l = m
    else:
        r = m

print(l)