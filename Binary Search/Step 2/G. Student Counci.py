k = int(input())
n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))


def f(x):
    sum = 0
    for i in range(n):
        sum += min(a[i], x)
    return sum >= k*x

l = 0
r = 25 * 1e9 + 10

while l + 1 < r:
    m = int((l+r)//2)
    if f(m):
        l =  m
    else:
        r = m

print(l)